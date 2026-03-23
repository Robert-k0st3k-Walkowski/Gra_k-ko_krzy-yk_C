#include <stdio.h>
#include "player.h"

void initializiePlayers(poiPlayer player1, poiPlayer player2)
{
	int choosingPlayer;

	choosingPlayer = (rand() % 2) + 1;

	printf("\nDecide, which player will be the \'player 1\' and which player will be the \'player 2\'.");

	player1->sign = 'X';

	player2->sign = 'O';

	printf("\n\nThe player which will start the game will be: \n");

	if (choosingPlayer == 1)
	{
		printf("Player 1 (\'X\' is your sign)!\n");
		player1->isStartingFirst = true;
		player2->isStartingFirst = false;
	}
	else if (choosingPlayer == 2)
	{
		printf("Player 2 (\'O\' is your sign)!\n");
		player2->isStartingFirst = true;
		player1->isStartingFirst = false;
	}
}

bool makeMove(char **board, poiPlayer GeneratedPlayer, poiPlayer Rival)
{
	int x = -1, y = -1;
	bool toMove = true;

	printf("\nInput, where do you want to put your sign (X and Y coordinates): \n");
	printf("X coordinate: ");
	scanf_s("%d", &x);
	printf("\n");
	printf("Y coordinate: ");
	scanf_s("%d", &y);

	if (*(*(board + x) + y) == ' ')
	{
		printf("\nGood job! You've made the right move! Next player turn started.\n\n");
		*(*(board + x) + y) = GeneratedPlayer->sign;
		toMove = false;
	}
	else
	{
		printf("\nYou put your sign into the wrong place. Try again.\n\n");
	}

	return toMove;
}