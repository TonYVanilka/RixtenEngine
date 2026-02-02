#pragma once
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum LogLevel : uint8_t {
    FATAL,
    ERROR,
    WARN,
    INFO,
    DEBUG
};

struct LoggerState {
    LogLevel logLevel = LogLevel::DEBUG;
};

struct LoggerBatch {
    static constexpr size_t BatchSize = 256;

    LogLevel levels[BatchSize];
    const char* files[BatchSize];
    std::string messages[BatchSize];
    uint32_t count = 0;
};

struct LoggerOutput {
    std::FILE* logFile = nullptr;
    bool logToFile = true;
    char buffer[1024];
    size_t bufferPos = 0;
};

namespace Logger {

    inline LoggerState g_logState = {};
    inline LoggerOutput g_LogOutput = {};
    inline LoggerBatch g_LogBatch = {};

    // utils
    inline const char* LogTypeToString(LogLevel type) {
        switch (type) {
            case LogLevel::FATAL: return "FATAL";
            case LogLevel::ERROR: return "ERROR";
            case LogLevel::WARN: return "WARN";
            case LogLevel::INFO: return "INFO";
            case LogLevel::DEBUG: return "DEBUG";
            default: return "UNKNOWN";
        }
    }

    inline const char* CutPath(const char* fullPath) {
        const char* last = fullPath;
        for (const char* p = fullPath; *p; ++p)
            if (*p == '/' || *p == '\\')
                last = p + 1;
        return last;
    }
    
    // Logger 

    inline void WriteBuffer(LoggerOutput& output) {
        if (output.logToFile && output.logFile) {
            std::fwrite(output.buffer, 1, output.bufferPos, output.logFile);
        }
        std::cout.write(output.buffer, output.bufferPos);
        output.bufferPos = 0;
    }

    inline void Init(LoggerOutput &output, const char* filePath = nullptr) {
        if (filePath) {
            output.logFile = std::fopen(filePath, "w");
            output.logToFile = true;
        }
    }

    template <typename... Args>
    inline void Log(LoggerState& state, LoggerBatch& batch, LogLevel lvl, const char* file, Args&&... args) {

        if (lvl > state.logLevel) return;

        std::ostringstream message;
        ((message << std::forward<Args>(args)), ...);

        uint32_t idx = batch.count;
        batch.levels[idx] = lvl;
        batch.files[idx] = file;
        batch.messages[idx] = message.str();
        batch.count++;

        if (lvl <= LogLevel::ERROR) {
            Logger::WriteAll();
        }

        if (batch.count >= LoggerBatch::BatchSize) {
            LogWrite(batch, g_LogOutput);
        }
    }

    inline void LogWrite(LoggerBatch& batch, LoggerOutput& output) {
        for (uint32_t i = 0; i < batch.count; ++i) {
            int written = std::snprintf(
                output.buffer + output.bufferPos,
                sizeof(output.buffer) - output.bufferPos,
                "[%s][%s] %s\n",
                Logger::LogTypeToString(batch.levels[i]),
                Logger::CutPath(batch.files[i]),
                batch.messages[i].c_str());

            output.bufferPos += written;

            if (output.bufferPos > sizeof(output.buffer) - 512)
                Logger::WriteBuffer(output);
        }

        batch.count = 0;
    }

    inline void WriteAll() {
        Logger::LogWrite(g_LogBatch, g_LogOutput);
        Logger::WriteBuffer(g_LogOutput);
    }

    inline void ShutDown(LoggerOutput& output) {
        Logger::WriteAll();
        if (output.logFile) {
            std::fclose(output.logFile);
            output.logFile = nullptr;
        }
    }
};

#ifdef DISABLE_LOGGING
    #define LOG_DEBUG(...) ((void)0)
    #define LOG_INFO(...) ((void)0)
    #define LOG_WARN(...) ((void)0)
    #define LOG_ERROR(...) ((void)0)
    #define LOG_FATAL(...) ((void)0)
#else
    #define LOG_DEBUG(...) Logger::Log(Logger::g_logState, Logger::g_LogBatch, LogLevel::DEBUG, __FILE__, __VA_ARGS__)
    #define LOG_INFO(...) Logger::Log(Logger::g_logState, Logger::g_LogBatch, LogLevel::INFO, __FILE__, __VA_ARGS__)
    #define LOG_WARN(...) Logger::Log(Logger::g_logState, Logger::g_LogBatch, LogLevel::WARN, __FILE__, __VA_ARGS__)
    #define LOG_ERROR(...) Logger::Log(Logger::g_logState, Logger::g_LogBatch, LogLevel::ERROR, __FILE__, __VA_ARGS__)
    #define LOG_FATAL(...) Logger::Log(Logger::g_logState, Logger::g_LogBatch, LogLevel::FATAL, __FILE__, __VA_ARGS__)
#endif  // DISABLE_LOGGING