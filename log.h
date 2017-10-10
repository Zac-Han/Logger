#ifndef MYLOG_H
#define MYLOG_H
#include <iostream>
#include <fstream>
#include <cstring>

enum LogLevel
{
    Info,
    Warning,
    Error
};

class Log
{
public:
    static const char * Infoprefix;
    static const char * Warningprefix;
    static const char * Errorprefix;
    static const int MAX_LEN = 1024;

//    static const char * FileDebug;
//    static const char * FileError;

    static Log& instance();

    void InitDefault(const char *DebugPath, const char *ErrorPath);

    void log(LogLevel level, const char * LogMessage, const char * args);
    void logInfo(const char * strFormat, ...);
    void logWarning(const char * strFormat, ...);
    void logError(const char * strFormat, ...);

protected:
    static std::ofstream mOutputDebug;
    static std::ofstream mOutputError;
    static Log* pInstance;

    std::string getTime();

private:
    Log();
    virtual ~Log();
    Log(const Log&);
    Log& operator = (const Log&);

    char FileDebug[MAX_LEN] = "Debug.txt";
    char FileError[MAX_LEN] = "Error.txt";;

};

#endif // MYLOG_H
