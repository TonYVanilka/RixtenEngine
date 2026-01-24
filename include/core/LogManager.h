#pragma once
#include <iostream>

enum TypeMessage {
    FATAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE
};

class Logger {

public:

    static Logger& GetInstance();

    void SetLogFilePath(const char* path);
    void SetLoggerLayer(TypeMessage type);

    template <typename... Args>
    void Log(TypeMessage type, const char* file, Args&&... args) {
        if (LogLevel <= type) {
            std::cout << LogTypeToString(type) << "::" << CutPath(file) << ' ';
            ((std::cout << std::forward<Args>(args)), ...);
            std::cout << std::endl;
        }
    }

    int DEBUG() {return dep += 1;};

private:

    Logger();
    ~Logger();

    const char* LogTypeToString(TypeMessage type);
    const char* CutPath(const char* fullPath);

    bool IsLoggingFile;
    const char* LogFilePath;
    TypeMessage LogLevel = TypeMessage::FATAL;

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    int dep = 0;
};

#ifdef DISABLE_LOGGING
    #define LOG_DEBUG(...) ((void)0)
    #define LOG_INFO(...) ((void)0)
    #define LOG_WARN(...) ((void)0)
    #define LOG_ERROR(...) ((void)0)
    #define LOG_FATAL(...) ((void)0)
#else
    #define LOG_DEBUG(...) Logger::GetInstance().Log(TypeMessage::DEBUG, __FILE__, __VA_ARGS__)
    #define LOG_INFO(...) Logger::GetInstance().Log(TypeMessage::INFO, __FILE__, __VA_ARGS__)
    #define LOG_WARN(...) Logger::GetInstance().Log(TypeMessage::WARN, __FILE__, __VA_ARGS__)
    #define LOG_ERROR(...) Logger::GetInstance().Log(TypeMessage::ERROR, __FILE__, __VA_ARGS__)
    #define LOG_FATAL(...) Logger::GetInstance().Log(TypeMessage::FATAL, __FILE__, __VA_ARGS__)
#endif  // DISABLE_LOGGING