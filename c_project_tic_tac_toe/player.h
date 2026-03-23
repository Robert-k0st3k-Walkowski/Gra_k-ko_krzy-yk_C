#pragma once
#include <stdbool.h>

struct player
{
	char sign;
	bool isStartingFirst;
};

typedef struct player Player;
typedef Player* poiPlayer;

void initializiePlayers(poiPlayer player1, poiPlayer player2);
bool makeMove(char** board, poiPlayer GeneratedPlayer, poiPlayer Rival);

