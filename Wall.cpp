/*
	Реализация класса для работы с расстановкой стен
	Пакман
	Дорофеев Д.Г. ИВТ-13БО
*/

#include"Wall.h"

Wall::Wall()
{
	_x = 0;
	_y = 0;
	_width = 0;
	_height = 0;
}

Wall::Wall(int x, int y, int width, int height)
{
	_x = x * PixInBlock;
	_y = y * PixInBlock;
	_width = width * PixInBlock;
	_height = height * PixInBlock;
}

