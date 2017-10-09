#include "log.h"
#include <iostream>

using namespace std;

int main()
{
    char Message[] = "Hello";
    Log::instance().logInfo("The Message is: %s\n", Message);
    Log::instance().logWarning("This is a Warning Message: %s\n", "Attention! Warning!");
    Log::instance().logError("An Error is detected: %s\n", "Fatal error detected!");
    return 0;
}
