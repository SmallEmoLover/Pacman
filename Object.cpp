/*
	Реализация класса-родителя объектов
	Пакман
	Кулаков Д.С. ИВТ-13БО
*/

#include"Object.h"

int Object::getX()
{
	return _x;
}

int Object :: getY()
{
	return _y;
}

int Object::getWidth()
{
	return _width;
}

int Object::getHeight()
{
	return _height;
}