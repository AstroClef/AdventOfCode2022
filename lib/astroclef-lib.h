/*
AstroClef Library: Header
by AstroClef

Description:
    This file contains addition code that help me code more fluently but also helps the curios inspector better understand how my code functions by improving readability.
    The code here can be (and will be by me) re-used accross multiple projects. 
*/

#ifndef ASTROCLEF_LIB_H
#define ASTROCLEF_LIB_H

#include <stdio.h>

//Makes coding and reading the code easier by modernizing the char* array by calling it a string.
typedef char *string;


/* Get String: Returns a string
Get String takes in a string as a "prompt" argument.
The function will then print the prompt to the screen and then collects and returns the user's unput as it's return value.
*/
string get_string(string prompt);

#endif