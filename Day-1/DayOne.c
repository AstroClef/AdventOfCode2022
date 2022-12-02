#include <stdio.h>
#include <stdlib.h>

//provides some more, almost unnecessary, readability - *cough* Line 24 *cough*
typedef enum {FIRST, SECOND, THIRD} ranks;

//Initialize Variables
char fileItem[7];

const int TOP_POCKETS = 3;
int topPockets[TOP_POCKETS];
int top_pockets_count = TOP_POCKETS - 1;

int activePocket = 0;

//Initialize Helper Functions
void readFileForNumbers(char* filename);
int sumCaloriesInTopPockets();

//------------------ ENTRY POINT --------------------
int main(void)
{
    readFileForNumbers("input.txt");
    printf("First: %i, Second: %i, Third: %i\n", topPockets[FIRST], topPockets[SECOND], topPockets[THIRD]);
    printf("Total Calories: %i\n", sumCaloriesInTopPockets());
    return 0;
}

//---------------- HELPER FUNCTIONS -----------------

// -- File Interaction
void readFileForNumbers(char* filename)
{
    //Open file and validate that it exists.
    FILE *input_file = fopen(filename, "r");
    if (!input_file)
    {
        printf("Error: No input file was found.\n");
        exit(-1);
    }

    //For all line items in the document...
    while(fgets(fileItem, 7, input_file) != NULL)
    {
        //...if the line is blank compare the active pocket with the top three pockets.
        if (fileItem[0] == '\n')
        {
            for (int i = 0; i < top_pockets_count; i ++)
            {
                if (topPockets[i] < activePocket)
                {
                    //If not at the end of the topPocket array
                    if(i < top_pockets_count)
                    {
                        //picks up the next lowest pocket and moves it down in rank one, so that the active pocket can take over.
                        int movingPocketPlace = topPockets[i+1];
                        topPockets[i+1] = topPockets[i];
                        //This check determines if a pocket will fall out of the top leaderboard.
                        if(i+2 <= TOP_POCKETS)
                        {
                            topPockets[i+2] = movingPocketPlace;
                        }
                    }
                    topPockets[i] = activePocket;
                    break;
                }
            }
            //reset and start counting the next pocket.
            activePocket = 0;
        }
        //add snack callories to the active pocket.
        activePocket += atoi(fileItem);
    }
    fclose(input_file);
}

//Sums together all top pockets.
int sumCaloriesInTopPockets()
{
    int totalCalories = 0;
    for (int i = 0; i <= top_pockets_count; i++)
    {
        totalCalories += topPockets[i];
    }
    return totalCalories;
}