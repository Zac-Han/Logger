#include "log.h"
#include <time.h>
#include <stdexcept>
#include <stdarg.h>

using namespace std;

const char * Log::Infoprefix = " [INFO] ";
const char * Log::Warningprefix = " [WARNING] ";
const char * Log::Errorprefix = " [ERROR] ";

ofstream Log::mOutputDebug;
ofstream Log::mOutputError;

Log* Log::pInstance = nullptr;

Log& Log::instance()
{
    if (pInstance == nullptr)
    {
        pInstance = new Log();
    }
    return *pInstance;
}

Log::Log()
{

}

Log::~Log()
{

}

void Log::InitDefault(const char * DebugPath, const char * ErrorPath)
{
    strcpy(Log::FileDebug, DebugPath);
    strcpy(Log::FileError, ErrorPath);
}

void Log::log(LogLevel level, const char * LogMessage, const char * args)
{
    switch(level)
    {
    case LogLevel::Info:
        logInfo(LogMessage, args);
        break;
    case LogLevel::Warning:
        logWarning(LogMessage, args);
        break;
    case LogLevel::Error:
        logError(LogMessage, args);
        break;
    default:
        break;
    }
}

void Log::logInfo(const char * strFormat, ...)
{
    char strInfo[MAX_LEN] = {0};
    va_list arg_ptr;
    va_start(arg_ptr, strFormat);
    vsprintf(strInfo, strFormat, arg_ptr);
    va_end(arg_ptr);

    mOutputDebug.open(FileDebug, ios::app);
    mOutputDebug <<"[" << getTime() << "]" << Infoprefix << strInfo << endl;
    mOutputDebug.close();

}

void Log::logWarning(const char * strFormat, ...)
{
    char strInfo[MAX_LEN] = {0};
    va_list arg_ptr;
    va_start(arg_ptr, strFormat);
    vsprintf(strInfo, strFormat, arg_ptr);
    va_end(arg_ptr);

    mOutputDebug.open(FileDebug, ios::app);
    mOutputDebug <<"[" << getTime() << "]" << Warningprefix << strInfo << endl;
    mOutputDebug.close();
    mOutputError.open(FileError, ios::app);
    mOutputError <<"[" << getTime() << "]" << Warningprefix << strInfo << endl;
    mOutputError.close();

}

void Log::logError(const char * strFormat, ...)
{


    char strInfo[MAX_LEN] = {0};
    va_list arg_ptr;
    va_start(arg_ptr, strFormat);
    vsprintf(strInfo, strFormat, arg_ptr);
    va_end(arg_ptr);

    mOutputDebug.open(FileDebug, ios::app);
    mOutputDebug <<"[" << getTime() << "]" << Errorprefix << strInfo << endl;
    mOutputDebug.close();
    mOutputError.open(FileError, ios::app);
    mOutputError <<"[" << getTime() << "]" << Errorprefix << strInfo << endl;
    mOutputError.close();

}

std::string Log::getTime()
{
    time_t t = time(0);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%d-%m-%y %X", localtime(&t));
    return tmp;
}
