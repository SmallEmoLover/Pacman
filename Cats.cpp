#include "Cats.h"

CatMode Cats::getStatus()
{
	return _status;
}

void Cats::setStatus(CatMode status)
{
	_status=x;
}

int Cats::getX()
{
	return _x;
}

int Cats::getY()
{
	return _y;
}

int Player::getHeight()
{
	return _height;
}

int Player::getWidth()
{
	return _width;
}

int Cats::MoveUp(int step)
{
	_y -= step;
}

int Cats::MoveDown(int step)
{
	_y += step;
}

int Cats::MoveRight(int step)
{
	_x += step;
}

int Cats::MoveLeft(int step)
{
	_x -= step;
}
