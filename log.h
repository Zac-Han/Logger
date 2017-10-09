#ifndef MYLOG_H
#define MYLOG_H
#include <iostream>
#include <fstream>
#include <cstring>


class Log
{
public:
    static const char * Infoprefix;
    static const char * Warningprefix;
    static const char * Errorprefix;

    static Log& instance();

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


};

#endif // MYLOG_H
