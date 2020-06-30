#include "Cat.h"

CatMode Cat::getStatus()
{
	return _status;
}

void Cat::setStatus(CatMode status)
{
	_status=status;
}

int Cat::getX()
{
	return _x;
}

int Cat::getY()
{
	return _y;
}

int Cat::getHeight()
{
	return _height;
}

int Cat::getWidth()
{
	return _width;
}

int Cat::MoveUp(int step)
{
	_y -= step;
}

int Cat::MoveDown(int step)
{
	_y += step;
}

int Cat::MoveRight(int step)
{
	_x += step;
}

int Cat::MoveLeft(int step)
{
	_x -= step;
}
