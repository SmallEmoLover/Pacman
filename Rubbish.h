/*
Библиотека для работы с собираемыми элементами.
Ширкунов А.В. ИВТ-13БО
*/
#pragma once
#include "Object.h"
#include"Player.h"

class Rubbish : public Object
{
public:
	//координата по Х
	int getX();
	//координата по У
	int getY();
	//Значение IsColected (собран элемент/не собран)
	bool getIsCollected();
	//Поменять IsColected
	void setIsCollected(bool value);
private:
	//статус (собран/не собран)
	bool IsCollected;
	int Object::x, y;
};