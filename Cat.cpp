#include "Cat.h"

Cat::Cat(int x_block, int y_block)
{
	_x = x_block * PixInBlock;
	_y = y_block * PixInBlock;
	_width = PixInBlock;
	_height = PixInBlock;
	_status = CHASE; 
}

void Cat::AIMove(int Px, int Py, int step, Wall* walls[WallCount])
{
	if ((_x < Px) && !IsWall(this, walls, RIGHT))
	{
		MoveRight(step);
		return;
	}
	if ((_y < Py) && !IsWall(this, walls, DOWN))
	{
		MoveDown(step);
		return;
	}
	if ((_x > Px) && !IsWall(this, walls, LEFT))
	{
		MoveLeft(step);
		return;
	}
	if ((_y > Py) && !IsWall(this, walls, UP))
	{
		MoveUp(step);
		return;
	}
}


CatMode Cat::getStatus()
{
	return _status;
}

void Cat::setStatus(CatMode status)
{
	_status = status;
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
