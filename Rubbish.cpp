#include <iostream>  
#include "Player.h"
#include "Object.h"
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
