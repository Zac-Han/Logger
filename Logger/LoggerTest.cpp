#include "mylog.h"
#include <string>

using namespace std;


int main()
{
    MyLog firstlog;

    firstlog.log("Error detected", LogLevel::LevelError);
    firstlog.log("This is an info", LogLevel::LevelInfo);
    firstlog.log("This is a Warning", LogLevel::LevelWarning);


    return 0;
}
