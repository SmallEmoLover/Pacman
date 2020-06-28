#include "Cats.h"

CatMode Cats::getStatus()
{
	return status;
}

void Cats::setStatus(CatMode x)
{
	status=x;
}

int Cats::getX()
{
	return x;
}

int Cats::getY()
{
	return y;
}

int Player::getHeight()
{
	return height;
}

int Player::getWidth()
{
	return width;
}

int Cats::MoveUp(int step)
{
	y -= step;
}

int Cats::MoveDown(int step)
{
	y += step;
}

int Cats::MoveRight(int step)
{
	x += step;
}

int Cats::MoveLeft(int step)
{
	x -= step;
}
