#include "Rubbish.h"

//���������� �� �
int Rubbish::getX()
{
	return _x;
}

//���������� �� �
int Rubbish::getY()
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

//�������� IsColected (������ �������/�� ������)
bool Rubbish::getIsCollected()
{
	return _IsCollected;
}

//�������� IsColected
void Rubbish::setIsCollected(bool value)
{
	_IsCollected = true;
}
