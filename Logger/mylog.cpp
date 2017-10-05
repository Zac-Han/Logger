#include "mylog.h"
#include <time.h>
#include <stdexcept>

using namespace std;

const string MyLog::Verbose = "VERBOSE";
const string MyLog::Info = "INFO";
const string MyLog::Warning = "WARNING";
const string MyLog::Error = "ERROR";

const char* MyLog::FileDebug = "Debug.txt";
const char* MyLog::FileError = "Error.txt";

MyLog::~MyLog()
{

}

MyLog::MyLog()
{

}


void MyLog::log(const std::string &LogMessage, LogLevel inLogLevel)
{
    logWriter(LogMessage, inLogLevel);
}

void MyLog::logWriter(const std::string &LogMessage, LogLevel inLogLevel)
{
    switch (inLogLevel) {
    case LogLevel::LevelVerbose:
        mOutputstream.open(FileDebug, ofstream::app);
        MyLog::LogText = MyLog::Verbose;
        break;
    case LogLevel::LevelInfo:
        mOutputstream.open(FileDebug, ofstream::app);
        MyLog::LogText = MyLog::Info;
        break;
    case LogLevel::LevelWarning:
        mOutputstream.open(FileError, ofstream::app);
        MyLog::LogText = MyLog::Warning;
        break;
    case LogLevel::LevelError:
        mOutputstream.open(FileError, ofstream::app);
        MyLog::LogText = MyLog::Error;
        break;
    default:
        break;
    }

    time_t t = time(0);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%d-%m-%y %X %A", localtime(&t));
    mOutputstream << "[" << tmp << "]" << endl;
    mOutputstream << "[" << MyLog::LogText << "]" << " : " << LogMessage << endl;
    mOutputstream.close();
}
