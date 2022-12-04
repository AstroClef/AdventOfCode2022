#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/astroclef-lib.h"
#include "../../lib/astroclef-aocdemo-helpers.h"

//File Management Global Variables
#define FILE_BUFFER_SIZE 4
#define PLAYER_CHOICE_BUFFER 2
string filename = "./strategy-guide.txt";
char fileItem[FILE_BUFFER_SIZE];


//Rock Paper Scissor Rules
int choicecount = 3;
typedef struct 
{
    string name;
    char guide_key[2];
    int scoreValue;
} rps_struct;
rps_struct rock = {"Rock", {'A', 'X'}, 1};
rps_struct paper = {"Paper", {'B', 'Y'}, 2};
rps_struct scissors = {"Scissors", {'C', 'Z'}, 3};

#define MAX_PLAYERS 10
int playercount = 2;
typedef struct {
    string name;
    int number;
    int score;
    rps_struct currentChoice;
} player;

//Function Declarations
void validateFile(FILE file);
void RPS_DeclareRules(void);
void RPS_UpdateScore(string battleround, rps_struct choices[], player players[]);
void RPS_BuildRoster(player players[]);

int main(void)
{
    //Open File
    printf("Opening File...\n");
    FILE *input_file = fopen(filename, "r");
    if (!input_file)
    {
        printf("Error: No input file was found.\n");
        exit(-1);
    }

    //Make Game Rules
    printf("Building Game Rules...\n");
    rps_struct availableChoices[] = {rock, paper, scissors};
    player roster[MAX_PLAYERS];
    RPS_BuildRoster(roster);

    //Game Runtime
    printf("Fetching Game Results\n");
    while(fgets(fileItem, FILE_BUFFER_SIZE, input_file) != NULL)
    {
        RPS_UpdateScore(fileItem, availableChoices, roster);
    }

    //File Cleanup
    printf("Cleaning up and closing out!\n");
    fclose(input_file);
    return 0;
}

void RPS_UpdateScore(string battleround, rps_struct choices[], player players[])
{
    for (int activePlayer = 0; activePlayer < playercount + playercount; activePlayer += PLAYER_CHOICE_BUFFER)
    {
        printf("Checking Player %i's choice: ", activePlayer);
        for(int possibleChoice = 0; possibleChoice < choicecount; possibleChoice++)
        {
            for (int possibleKey = 0; possibleKey < 2; possibleKey++)
            {
                if(battleround[activePlayer] == choices[possibleChoice].guide_key[possibleKey])
                {
                    printf("%c\n", battleround[activePlayer]);
                    if(activePlayer == 0)
                    {
                        memcpy(&players[activePlayer].currentChoice, &choices[possibleChoice], sizeof choices[possibleChoice]);
                    }
                    memcpy(&players[activePlayer-1].currentChoice, &choices[possibleChoice], sizeof choices[possibleChoice]);
                }
            }
        }
    }
    printf("%s %i: %s -VS- %s %i: %s\n", 
        players[0].name, players[0].number, players[0].currentChoice.name,
        players[1].name, players[1].number, players[1].currentChoice.name);
}

void RPS_BuildRoster(player players[])
{
    printf("Building Roster...\n");
    for (int i = 0; i < playercount; i++)
    {
        players[i].name = "Player";
        players[i].number = i + 1;
        players[i].score = 0;
    }
}