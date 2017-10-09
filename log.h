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

    // void logInfo(const char *strFormat);

    void logInfo(const char * strFormat, ...);

protected:
    std::ofstream mOutputDebug;
    static Log* pInstance;

private:
    Log();
    virtual ~Log();
    Log(const Log&);
    Log& operator = (const Log&);


};

#endif // MYLOG_H
