#include "Rubbish.h"

//���������� �� �
int Rubbish::getX()
{
	return x;
}

//���������� �� �
int Rubbish::getY()
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

//�������� IsColected (������ �������/�� ������)
bool Rubbish::getIsCollected()
{
	return IsCollected;
}

//�������� IsColected
void Rubbish::setIsCollected(bool value)
{
	IsCollected = true;
}
