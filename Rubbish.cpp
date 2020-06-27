#include <iostream>  
#include "Player.h"
#include "Object.h"
#include "Rubbish.h"

//координата по Х
int Rubbish::getX()
{
	return x;
}

//координата по Х
int Rubbish::getY()
{
	return y;
}

//Значение IsColected (собран элемент/не собран)
bool Rubbish::getIsCollected()
{
	return IsCollected;
}

//Поменять IsColected
void Rubbish::setIsCollected(bool value)
{
	IsCollected = true;
}
