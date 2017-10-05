#include "mylog.h"
#include <string>

using namespace std;


int main()
{
    MyLog::instance().log("Test Information", LogLevel::LevelInfo);
    MyLog::instance().logError("An Error is detected!");

    return 0;
}
