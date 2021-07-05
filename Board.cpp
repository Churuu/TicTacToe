#include "Board.h";


Board::Board()
{

}

void Board::ChangeBrick(Brick::BrickType type)
{
	brick.brickType = type;

}

Brick Board::GetBrick()
{
	return brick;
}
