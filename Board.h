#pragma once

#include "Brick.h";



class Board {
public:
	Board();
	bool locked = false;
	Brick brick;

	void ChangeBrick(Brick::BrickType type);
	Brick GetBrick();
};
