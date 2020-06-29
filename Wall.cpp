#include"Wall.h"
Wall::Wall(int x, int y, int width, int height, way direction, bool isCorner)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_direction = direction;
	_isCorner = isCorner;
}
way Wall::getDirection()
{
	return _direction;
}
int  Wall::setDirection(way direction)
{
	_direction = direction;
}

