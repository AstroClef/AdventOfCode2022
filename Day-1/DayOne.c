#include <stdio.h>
#include <stdlib.h>

//making a string type -- i like strings
typedef char* string;

//Prepare file input
FILE *input_file = fopen("./input.txt", "r");

//Initialize Variables
string stringFromFile;
int theLargestPocket = 0;

//Initialize Helper Functions
bool fileValidation(void);
void readFile(void);


//------------------ ENTRY POINT --------------------
int main(void)
{
    fileValidation();
    readFileForNumbers();
}


//---------------- HELPER FUNCTIONS -----------------

// -- File Interaction
bool fileValidation(void)
{
    if (!input_file)
    {
        prinf("Error: No input file was found.");
        exit(-1);
    }
}

void readFileForNumbers(void)
{
    while (fscanf(input_file, "%s", stringFromFile) != EOF)
    {
        printf("%s", stringFromFile);
    }
}


