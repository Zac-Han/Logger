#include "log.h"
#include <time.h>
#include <stdexcept>
#include <stdarg.h>

using namespace std;

const char * Log::Infoprefix = "[INFO]";
const char * Log::Warningprefix = "[WARNING]";
const char * Log::Errorprefix = "[ERROR]";

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

void Log::logInfo(const char * strFormat, ...)
{
    char strInfo[100] = {0};
    va_list arg_ptr;
    va_start(arg_ptr, strFormat);
    vsprintf(strInfo, strFormat, arg_ptr);
    va_end(arg_ptr);

    mOutputDebug.open("Debug.txt", ios::app);
    mOutputDebug <<"[" << getTime() << "]" << Infoprefix << strInfo << endl;
    mOutputDebug.close();

}

void Log::logWarning(const char * strFormat, ...)
{
    char strInfo[100] = {0};
    va_list arg_ptr;
    va_start(arg_ptr, strFormat);
    vsprintf(strInfo, strFormat, arg_ptr);
    va_end(arg_ptr);

    mOutputDebug.open("Debug.txt", ios::app);
    mOutputDebug <<"[" << getTime() << "]" << Warningprefix << strInfo << endl;
    mOutputDebug.close();
    mOutputError.open("Error.txt", ios::app);
    mOutputError <<"[" << getTime() << "]" << Warningprefix << strInfo << endl;
    mOutputError.close();

}

void Log::logError(const char * strFormat, ...)
{


    char strInfo[100] = {0};
    va_list arg_ptr;
    va_start(arg_ptr, strFormat);
    vsprintf(strInfo, strFormat, arg_ptr);
    va_end(arg_ptr);

    mOutputDebug.open("Debug.txt", ios::app);
    mOutputDebug <<"[" << Log::getTime() << "]" << Errorprefix << strInfo << endl;
    mOutputDebug.close();
    mOutputError.open("Error.txt", ios::app);
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
