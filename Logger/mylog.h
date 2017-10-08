#ifndef MYLOG_H
#define MYLOG_H
#include <iostream>
#include <fstream>
#include <string>

enum LogLevel
{
    LevelInfo,
    LevelWarning,
    LevelError
};

class MyLog
{
public:
    static const std::string Info;
    static const std::string Warning;
    static const std::string Error;
    std::string LogText;

    static MyLog& instance();

    void logInfo(const std::string& LogMessage);
    void logWarning(const std::string& LogMessage);
    void logError(const std::string& LogMessage);


    void log(const std::string& LogMessage, LogLevel inLogLevel = LogLevel::LevelInfo);

protected:
    static const char* FileDebug;
    static const char* FileError;

    std::ofstream mOutputDebug;
    std::ofstream mOutputError;
    static MyLog* pInstance;
    void logWriter(const std::string& LogMessage, LogLevel);


private:
    MyLog();
    virtual ~MyLog();
    MyLog(const MyLog&);
    MyLog& operator = (const MyLog&);


};

#endif // MYLOG_H
