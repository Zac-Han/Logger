#ifndef MYLOG_H
#define MYLOG_H
#include <iostream>
#include <fstream>
#include <string>

enum LogLevel
{
    LevelVerbose,
    LevelInfo,
    LevelWarning,
    LevelError
};

class MyLog
{
public:
    static const std::string Verbose;
    static const std::string Info;
    static const std::string Warning;
    static const std::string Error;
    std::string LogText;

    MyLog();

    virtual ~MyLog();


    void log(const std::string& LogMessage, LogLevel inLogLevel = LogLevel::LevelVerbose);

protected:
    static const char* FileDebug;
    static const char* FileError;

    std::ofstream mOutputstream;

    void logWriter(const std::string& LogMessage, LogLevel);


private:


};

#endif // MYLOG_H
