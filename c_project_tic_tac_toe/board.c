#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "board.h"
#include "player.h"

char** initializeBoard(char **board, int* sizeX, int* sizeY)
{
    if ((*sizeX != *sizeY) || (*sizeX < 0) || (*sizeY < 0) || (*sizeX % 2 != 1) || (*sizeY % 2 != 1) || (*sizeX < 7) || (*sizeY < 7))
    {
        *sizeX = 7;
        *sizeY = 7;

        printf("WRONG INPUT! DEFAULT VALUES ASSIGNED!\n\n");
    }

    board = (char**)malloc(*(sizeX) * sizeof(char*));

    for (int i = 0; i < *sizeX; i++)
    {
        board[i] = (char*)malloc(*(sizeY) * sizeof(char));
    }


    for (int i = 0; i < *sizeX; i++)
    {        
        for (int j = 0; j < *sizeY; j++)
        {
            if ((i == 0 || i == *sizeX - 1))
            {
                *(*(board + i) + j) = '#';
            }
            else if ((j == 0 || j == *sizeY - 1))
            {
                *(*(board + i) + j) = '#';
            }
            else
            {
                *(*(board + i) + j) = ' ';
            }
            
        }
    }

    for (int i = 1; i < *sizeX - 1; i++)
    {
        for (int j = 1; j < *sizeY - 1; j++)
        {
            if ((j%2 == 0) && (i%2 == 1))
            {
                *(*(board + i) + j) = '|';
            }
            else if ((i%2 == 0) && (j%2 == 1))
            {
                *(*(board + i) + j) = '-';
            }
            else if ((i % 2 == 0) && (j % 2 == 0))
            {
                *(*(board + i) + j) = '+';
            }
            else
            {
                *(*(board + i) + j) = ' ';
            }
        }
    }

    printf("   ");

    for (int i = 0; i < *sizeX; i++)
    {
        printf("%d", i);
    }

    printf("\n");


    for (int i = 0; i < *sizeX; i++)
    {
        printf("%2d ", i);

        for (int j = 0; j < *sizeY; j++)
        {
            printf("%c", *(*(board + i) + j));
        }
        printf("\n");
    }

    return board;

}

void showBoard(char** board, int *sizeX, int *sizeY)
{

    printf("   ");

    for (int i = 0; i < *sizeX; i++)
    {
        printf("%d", i);
    }

    printf("\n");


    for (int i = 0; i < *sizeX; i++)
    {
        printf("%2d ", i);

        for (int j = 0; j < *sizeY; j++)
        {
            printf("%c", *(*(board + i) + j));
        }
        printf("\n");
    }
}


WinnerCheck checkWhoWins(char** board, poiPlayer GivenPlayer1, poiPlayer GivenPlayer2, int* sizeX, int* sizeY)
{
    int amountOfSignP1 = 0;
    int amountOfSignP2 = 0;

    WinnerCheck endOfGame = none;
    int emptyCells = 0;

    for (int i = 1; i < (*sizeX) - 1; i += 2)
    {
        amountOfSignP1 = amountOfSignP2 = 0;

        for (int j = 1; j < (*sizeY) - 1; j += 2)
        {
            char current = *(*(board + i) + j);

            if (current == ' ')
            {
                emptyCells++;
            }

            if (current == GivenPlayer1->sign)
            {
                amountOfSignP1++;
                amountOfSignP2 = 0;

                if (amountOfSignP1 >= 3) return player1;
            }
            else if (current == GivenPlayer2->sign)
            {
                amountOfSignP2++;
                amountOfSignP1 = 0;

                if (amountOfSignP2 >= 3) return player2;
            }
            else
            {
                amountOfSignP1 = 0;
                amountOfSignP2 = 0;
            }
        }
    }

    for (int j = 1; j < (*sizeY) - 1; j += 2)
    {
        amountOfSignP1 = amountOfSignP2 = 0;

        for (int i = 1; i < (*sizeX) - 1; i += 2)
        {
            char current = *(*(board + i) + j);

            if (current == GivenPlayer1->sign)
            {
                amountOfSignP1++;
                amountOfSignP2 = 0;

                if (amountOfSignP1 >= 3) return player1;
            }
            else if (current == GivenPlayer2->sign)
            {
                amountOfSignP2++;
                amountOfSignP1 = 0;

                if (amountOfSignP2 >= 3) return player2;
            }
            else
            {
                amountOfSignP1 = 0;
                amountOfSignP2 = 0;
            }
        }
    }

    int maxPlayableX = *sizeX - 2;
    int maxPlayableY = *sizeY - 2;

    for (int i = 1; i <= maxPlayableX; i += 2)
    {
        for (int j = 1; j <= maxPlayableY; j += 2)
        {
            char current = *(*(board + i) + j);

            if (current == ' ' || current == '|' || current == '-' || current == '+' || current == '#')
                continue;

            if ((i + 4) <= maxPlayableX && (j + 4) <= maxPlayableY)
            {
                if (current == *(*(board + (i + 2)) + (j + 2)) &&
                    current == *(*(board + (i + 4)) + (j + 4)))
                {
                    if (current == GivenPlayer1->sign) return player1;
                    if (current == GivenPlayer2->sign) return player2;
                }
            }

            if ((i + 4) <= maxPlayableX && (j - 4) >= 1)
            {
                if (current == *(*(board + (i + 2)) + (j - 2)) &&
                    current == *(*(board + (i + 4)) + (j - 4)))
                {
                    if (current == GivenPlayer1->sign) return player1;
                    if (current == GivenPlayer2->sign) return player2;
                }
            }
        }
    }

    if (emptyCells == 0)
    {
        endOfGame = draw;
    }
    else
    {
        endOfGame = none;
    }

    return endOfGame;
}
