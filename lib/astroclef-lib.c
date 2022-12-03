
#include "astroclef-lib.h"

string get_string(string prompt)
{
    string userInput;
    printf("%s", prompt);
    scanf("%s", &userInput);
    return userInput;
}