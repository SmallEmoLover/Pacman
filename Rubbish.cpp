#include "Rubbish.h"

//координата по X
int Rubbish::getX()
{
	return _x;
}

//координата по Y
int Rubbish::getY()
{
	return _y;
}

int Rubbish::getHeight()
{
	return _height;
}

int Rubbish::getWidth()
{
	return _width;
}

//возвращает _IsColected (собран элемент/не собран)
bool Rubbish::getIsCollected()
{
	return _IsCollected;
}

//изменить _IsColected
void Rubbish::setIsCollected(bool value)
{
	_IsCollected = true;
}
