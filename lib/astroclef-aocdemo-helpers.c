#include <string.h>
#include <stdbool.h>
#include "astroclef-aocdemo-helpers.h"

bool modeCheck(void)
{
    string response;
    
    //Ask the first time & while the response is not Y/y or N/n, keep asking.
    do
    {
        response = get_string("Before we begin, would you like to see the detailed output to show how I rank the Elf Pockets? [y/n]");
        printf("%s", response);
    } while ((strcasecmp(response, "y") != 0 && strcasecmp(response, "n") != 0));

    //If the response is Y or y
    if (strcasecmp(response, "y") == 0)
    {
        return true;
    }
    return false;
}