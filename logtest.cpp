#include "log.h"
#include <iostream>

using namespace std;

int main()
{
    char Message[] = "Hello";
    Log::instance().logInfo("The Message is: %s\n", Message);
    return 0;
}
