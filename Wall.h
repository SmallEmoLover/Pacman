/*
Библиотека для работы с расстановкой стен
Пакман
Дорофеев Д.Г. ИВТ-13БО
*/
#pragma once
#include"Object.h"
#include"Player.h"
class Wall : public Object
{
public:
	Wall();
	//координата начала по Х
	int getX();
	//координата начала по У
	int getY();
	//настройка ширины одного кубика
	void setWidth();
	//настройка длинны стены
	int setLenght(int x);
	//настройка направления стены
	int setDirection(way x);
	//направление стены(u/d/l/r)
	way getDirection();
private:
	way direction;
	bool isCorner;
};

