#include"player.h"
#include"board.h"
#include"game.h"

void game(char** board, poiPlayer GivenPlayer1, poiPlayer GivenPlayer2, int* sizeX, int* sizeY)
{
    bool GivenPlayer1MadeMove, GivenPlayer2MadeMove;
    WinnerCheck endOfGame = none;

    while (endOfGame == none)
    {

        if (GivenPlayer1->isStartingFirst)
        {
            GivenPlayer1MadeMove = makeMove(board, GivenPlayer1, GivenPlayer2);
            while (GivenPlayer1MadeMove)
            {
                showBoard(board, sizeX, sizeY);
                printf("The player with sign: %c make a move now.\n", GivenPlayer1->sign);
                GivenPlayer1MadeMove = makeMove(board, GivenPlayer1, GivenPlayer2);
            }
            showBoard(board, sizeX, sizeY);

            endOfGame = checkWhoWins(board, GivenPlayer1, GivenPlayer2, sizeX, sizeY);
            if (endOfGame != none) break;

            printf("The player with sign: %c make a move now.\n", GivenPlayer2->sign);
            GivenPlayer2MadeMove = makeMove(board, GivenPlayer2, GivenPlayer1);
            while (GivenPlayer2MadeMove)
            {
                showBoard(board, sizeX, sizeY);
                printf("The player with sign: %c make a move now.\n", GivenPlayer2->sign);
                GivenPlayer2MadeMove = makeMove(board, GivenPlayer2, GivenPlayer1);
            }
            showBoard(board, sizeX, sizeY);

            endOfGame = checkWhoWins(board, GivenPlayer1, GivenPlayer2, sizeX, sizeY);
        }
        else
        {
            GivenPlayer2MadeMove = makeMove(board, GivenPlayer2, GivenPlayer1);

            while (GivenPlayer2MadeMove)
            {
                showBoard(board, sizeX, sizeY);
                printf("The player with sign: %c make a move now.\n", GivenPlayer2->sign);
                GivenPlayer2MadeMove = makeMove(board, GivenPlayer2, GivenPlayer1);
            }
            showBoard(board, sizeX, sizeY);

            endOfGame = checkWhoWins(board, GivenPlayer1, GivenPlayer2, sizeX, sizeY);
            if (endOfGame != none) break;

            printf("The player with sign: %c make a move now.\n", GivenPlayer1->sign);

            GivenPlayer1MadeMove = makeMove(board, GivenPlayer1, GivenPlayer2);

            while (GivenPlayer1MadeMove)
            {
                showBoard(board, sizeX, sizeY);
                printf("The player with sign: %c make a move now.\n", GivenPlayer1->sign);
                GivenPlayer1MadeMove = makeMove(board, GivenPlayer1, GivenPlayer2);
            }
            showBoard(board, sizeX, sizeY);
            
            endOfGame = checkWhoWins(board, GivenPlayer1, GivenPlayer2, sizeX, sizeY);
        }
    }

    if (endOfGame == player1)
    {
        printf("\nPlayer 1 Wins! Congratulations!\n");
    }
    else if (endOfGame == player2)
    {
        printf("\nPlayer 2 Wins! Congratulations!\n");
    }
    else
    {
        printf("Draw! Sorry, nobody wins.\n");
    }
}