#include "Cat.h"

way Cat::AIMove(int Px, int Py, int step, Wall* walls[WallCount])
{
	if (_x < Px) 
		if (!IsWall(_x+1, _y, walls))
			return RIGHT;
		else if (!IsWall(_x - 1, _y, walls))
			return LEFT;
	if (_y < Py)
		if (!IsWall(_x, _y+1, walls))
			return DOWN;
		else if (!IsWall(_x - 1, _y, walls))
			return UP;
	if (_x > Px)
		if (!IsWall(_x - 1, _y, walls))
			return LEFT;
		else if (!IsWall(_x + 1, _y, walls))
			return RIGHT;
	if (_y > Py)
		if (!IsWall(_x - 1, _y, walls))
			return UP;
		else if (!IsWall(_x, _y + 1, walls))
			return DOWN;

}

CatMode Cat::getStatus()
{
	return _status;
}

void Cat::setStatus(CatMode status)
{
	_status=status;
}
void Cat::MoveUp(int step)
{
	_y -= step;
}

void Cat::MoveDown(int step)
{
	_y += step;
}

void Cat::MoveRight(int step)
{
	_x += step;
}

void Cat::MoveLeft(int step)
{
	_x -= step;
}
