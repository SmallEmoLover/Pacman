#include"Wall.h"
Wall::Wall()
{
	lenght = 0;
	direction = UP;
	x = y = 0;
	width = height = 1;
}
way Wall::getDirection()
{
	return direction;
}
int Wall::getLenght()
{
	return lenght;
}
int  Wall::setDirection(way x)
{
	direction = x;
}
int Wall::setLenght(int x) {
	lenght = x;
}


