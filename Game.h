#pragma once
#include "Board.h"

#include <iostream>

using namespace std;

bool gameEnded = false;
int playerTurn = 2;


class Game {
public:
	Game();
	void Loop();
	void UpdateBoard();
	void CheckWinner();
	void GetPlayerTurn();
	void GameEnded(int winner);
	void SetBrickOnBoard();
	Board board[9];

};
