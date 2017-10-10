#include "log.h"
#include <iostream>

using namespace std;

int main()
{
    char Message[] = "Hello";

    // Log::instance().InitDefault("./Logfiles/Debug.txt", "./Logfiles/Error.txt");
    Log::instance().logInfo("The Message is: %s\n", Message);
    Log::instance().logWarning("This is a Warning Message: %s\n", "Attention! Warning!");
    Log::instance().logError("An Error is detected: %s\n", "xxx not found");
    Log::instance().log(Info, "Another message: %s\n", "Good.");
    Log::instance().log(Error, "2nd error: %s\n", "Error 2.");
    return 0;
}
