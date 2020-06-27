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