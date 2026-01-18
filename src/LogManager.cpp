#include "core/LogManager.h"
#include <iostream>

Logger& Logger::GetInstance() {
    static Logger instance;
    return instance;
}

void Logger::AddLogFile(const char* path) {
    LogFilePath = path;
    IsLoggingFile = true;
}

void Logger::Log(TypeMessage type, const char* message) {
    
    std::cout << LogTypeToString(type) << ": " << message << std::endl;
}

Logger::Logger() {
#ifdef DISABLE_LOGGING
    std::cout << "Logger disable" << std::endl;
#else 
    std::cout << "Logger init" << std::endl;
#endif
}

Logger::~Logger() {
}

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