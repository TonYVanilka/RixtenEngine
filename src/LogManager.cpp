#include "core/LogManager.h"

Logger::Logger() : IsLoggingFile(false) {
#ifdef DISABLE_LOGGING
    std::cout << "Logger disable" << std::endl;
#else
    std::cout << "Logger init" << std::endl;
#endif
}

Logger::~Logger() {
}

Logger& Logger::GetInstance() {
    static Logger instance;
    return instance;
}

void Logger::SetLogFilePath(const char* path) {
    LogFilePath = path;
    IsLoggingFile = true;
}

void Logger::SetLoggerLayer(TypeMessage type) {LogLevel = type;}

const char* Logger::LogTypeToString(TypeMessage type) {
    switch (type) {
        case TypeMessage::FATAL:
            return "FATAL";
        case TypeMessage::ERROR:
            return "ERROR";
        case TypeMessage::WARN:
            return "WARN";
        case TypeMessage::INFO:
            return "INFO";
        case TypeMessage::DEBUG:
            return "DEBUG";
        case TypeMessage::TRACE:
            return "TRACE";
        default:
            return "UNKNOWN";
    }
}

const char* Logger::CutPath(const char* fullPath) {
    const char* lastSlash = strrchr(fullPath, '/');
    const char* lastBackslash = strrchr(fullPath, '\\');
    const char* lastSeparator = (lastSlash > lastBackslash) ? lastSlash : lastBackslash;

    return lastSeparator ? lastSeparator + 1 : fullPath;
}