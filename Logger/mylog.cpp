#include "mylog.h"
#include <time.h>
#include <stdexcept>

using namespace std;

const string MyLog::Info = "INFO";
const string MyLog::Warning = "WARNING";
const string MyLog::Error = "ERROR";

const char* MyLog::FileDebug = "Debug.txt";
const char* MyLog::FileError = "Error.txt";

MyLog* MyLog::pInstance = nullptr;

MyLog& MyLog::instance()
{
    if (pInstance == nullptr)
    {
        pInstance = new MyLog();
    }
    return *pInstance;
}

MyLog::MyLog()
{

}

MyLog::~MyLog()
{

}

void MyLog::log(const std::string& LogMessage, LogLevel inLogLevel)
{
    logWriter(LogMessage, inLogLevel);
}

void MyLog::logInfo(const std::string& LogMessage)
{
    logWriter(LogMessage, LogLevel::LevelInfo);
}

void MyLog::logWarning(const std::string& LogMessage)
{
    logWriter(LogMessage, LogLevel::LevelWarning);
}

void MyLog::logError(const std::string& LogMessage)
{
    logWriter(LogMessage, LogLevel::LevelError);
}

void MyLog::logWriter(const std::string &LogMessage, LogLevel inLogLevel)
{
    time_t t = time(0);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%d-%m-%y %X", localtime(&t));

    switch (inLogLevel) {
    case LogLevel::LevelInfo:
        mOutputDebug.open(FileDebug, ofstream::app);
        MyLog::LogText = MyLog::Info;

        break;
    case LogLevel::LevelWarning:
        mOutputDebug.open(FileDebug, ofstream::app);
        mOutputError.open(FileError, ofstream::app);
        MyLog::LogText = MyLog::Warning;
        mOutputError << "[" << tmp << "]";
        mOutputError << "[" << MyLog::LogText << "]" << " : " << LogMessage << endl;
        mOutputError.close();
        break;
    case LogLevel::LevelError:
        mOutputDebug.open(FileDebug, ofstream::app);
        mOutputError.open(FileError, ofstream::app);
        MyLog::LogText = MyLog::Error;
        mOutputError << "[" << tmp << "]";
        mOutputError << "[" << MyLog::LogText << "]" << " : " << LogMessage << endl;
        mOutputError.close();
        break;
    default:
        break;
    }

    mOutputDebug << "[" << tmp << "]";
    mOutputDebug << "[" << MyLog::LogText << "]" << " : " << LogMessage << endl;
    mOutputDebug.close();

}
