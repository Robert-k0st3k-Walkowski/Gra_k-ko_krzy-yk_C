#pragma once
#include "player.h"

enum WhoWins
{
	player1,
	player2,
	draw,
	none
};

typedef enum WhoWins WinnerCheck;

char** initializeBoard(char** board, int* sizeX, int* sizeY);
void showBoard(char** board, int* sizeX, int* sizeY);
WinnerCheck checkWhoWins(char** board, poiPlayer player1, poiPlayer player2, int* sizeX, int* sizeY);
