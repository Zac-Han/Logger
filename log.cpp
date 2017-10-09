#include "log.h"
#include <time.h>
#include <stdexcept>
#include <stdarg.h>

using namespace std;

const char * Log::Infoprefix = "[INFO]";
const char * Log::Warningprefix = "[WARNING]";
const char * Log::Errorprefix = "[ERROR]";

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
    time_t t = time(0);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%d-%m-%y %X", localtime(&t));

    char strInfo[100] = {0};
    va_list arg_ptr;
    va_start(arg_ptr, strFormat);
    vsprintf(strInfo, strFormat, arg_ptr);
    va_end(arg_ptr);
    cout <<"[" << tmp << "]" << Infoprefix << strInfo << endl;

    ofstream mOutputDebug;
    mOutputDebug.open("Debug.txt", ios::app);
    mOutputDebug <<"[" << tmp << "]" << Infoprefix << strInfo << endl;
    mOutputDebug.close();

}
