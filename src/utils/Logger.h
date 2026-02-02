#pragma once
#include <cstdio>
#include <iostream>

enum LogLevel : uint8_t {
    FATAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE
};

struct LoggerState {
    LogLevel logLevel = LogLevel::FATAL;
    std::FILE* logFile = nullptr;
    bool logToFile = false;
};

extern LoggerState* g_logger;

namespace Logger {

    inline void Init(LoggerState &state, const char* filePath = nullptr) {
        if (filePath) {
            state.logFile = std::fopen(filePath, "w");
            state.logToFile = true;
        };
    };

    inline void ShutDown(LoggerState &state) {
        if (state.logFile) {
            std::fclose(state.logFile);
            state.logFile = nullptr;
        }
    };

    template <typename... Args>
    inline void Log(LoggerState state, LogLevel lvl, const char* file, Args&&... args) {
        if (lvl >= state.logLevel) return;

        std::cout << '[' << LogTypeToString(lvl) << "][" << CutPath(file) << "] ";
        ((std::cout << std::forward<Args>(args)), ...);
        std::cout << std::endl;
    }

    inline const char* LogTypeToString(LogLevel type) {
        switch (type) {
            case LogLevel::FATAL:
                return "FATAL";
            case LogLevel::ERROR:
                return "ERROR";
            case LogLevel::WARN:
                return "WARN";
            case LogLevel::INFO:
                return "INFO";
            case LogLevel::DEBUG:
                return "DEBUG";
            case LogLevel::TRACE:
                return "TRACE";
            default:
                return "UNKNOWN";
        }
    };

    inline const char* CutPath(const char* fullPath) {
        const char* last = fullPath;
        for (const char* p = fullPath; *p; ++p)
            if (*p == '/' || *p == '\\')
                last = p + 1;
        return last;
    };

};

#ifdef DISABLE_LOGGING
    #define LOG_DEBUG(...) ((void)0)
    #define LOG_INFO(...) ((void)0)
    #define LOG_WARN(...) ((void)0)
    #define LOG_ERROR(...) ((void)0)
    #define LOG_FATAL(...) ((void)0)
#else
    #define LOG_DEBUG(...) Logger::Log(*g_logger, LogLevel::DEBUG, __FILE__, __VA_ARGS__)
    #define LOG_INFO(...) Logger::Log(*g_logger, LogLevel::INFO, __FILE__, __VA_ARGS__)
    #define LOG_WARN(...) Logger::Log(*g_logger, LogLevel::WARN, __FILE__, __VA_ARGS__)
    #define LOG_ERROR(...) Logger::Log(*g_logger, LogLevel::ERROR, __FILE__, __VA_ARGS__)
    #define LOG_FATAL(...) Logger:Log(*g_logger, LogLevel::FATAL, __FILE__, __VA_ARGS__)
#endif  // DISABLE_LOGGING