#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "board.h"
#include "player.h"
#include "game.h"

void menu();

int main()
{
	int choice;
    char **board = NULL;

    poiPlayer player1 = malloc(sizeof(Player));
    poiPlayer player2 = malloc(sizeof(Player));

    srand(time(NULL));

	menu();

    printf("\nPlease, choose option: ");
    scanf_s("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\n1 Clicked\n\n");

        int sX = 0, sY = 0;
        int* PoisX = &sX;
        int* PoisY = &sY;

        printf("\nGive me the number of ROWS (take a number+1 for border) for your game board: ");
        scanf_s("%d", &sX);

        printf("\n\n");

        printf("\nGive me the number of COLUMNS (take a number+1 for border) for your game board: ");
        scanf_s("%d", &sY);

        printf("\n\n");

        char** initializedBoard = initializeBoard(board, PoisX, PoisY);
        initializiePlayers(player1, player2);

        game(initializedBoard, player1, player2, PoisX, PoisY);

        break;
    case 2:
        printf("\n2 Clickced\n\n");
        printf("This is my simple implamantation a popular \'tic-tac-toe\' game in C langauge!\n");
        break;
    default:
        printf("Sorry, you clicked wrong button!\n");
        break;
    }

}

void menu()
{
	printf("WELCOME TO MY TIC TAC TOE GAME!!!\n");
	printf("---------------------------------\n");
	printf("\'1\' <- Start game\n");
	printf("\'2\' <- More about my game\n");
}


