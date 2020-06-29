#include"Wall.h"
Wall::Wall()
{
	direction = UP;
}
way Wall::getDirection()
{
	return direction;
}
int  Wall::setDirection(way x)
{
	direction = x;
}

