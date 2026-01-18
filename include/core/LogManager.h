#pragma once 

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

    void AddLogFile(const char* path);

    void Log(TypeMessage type, const char* message);

private:

    Logger();
    ~Logger();

    const char* LogTypeToString(TypeMessage type);

    bool IsLoggingFile = false;
    const char* LogFilePath;

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

};

#ifdef DISABLE_LOGGING
    #define LOG_DEBUG(...) ((void)0)
    #define LOG_INFO(...) ((void)0)
    #define LOG_WARN(...) ((void)0)
    #define LOG_ERROR(...) ((void)0)
    #define LOG_FATAL(...) ((void)0)
#else
    #define LOG_DEBUG(...) Logger::GetInstance().Log(TypeMessage::DEBUG, __VA_ARGS__)
    #define LOG_INFO(...) Logger::GetInstance().Log(TypeMessage::INFO, __VA_ARGS__)
    #define LOG_WARN(...) Logger::GetInstance().Log(TypeMessage::WARN, __VA_ARGS__)
    #define LOG_ERROR(...) Logger::GetInstance().Log(TypeMessage::ERROR, __VA_ARGS__)
    #define LOG_FATAL(...) Logger::GetInstance().Log(TypeMessage::FATAL, __VA_ARGS__)
#endif  // DISABLE_LOGGING