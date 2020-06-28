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
	int setWidth();
	//настройка высоты одного кубика
	int setHeight();
	//получение длинны стены
	int getLenght();
	//настройка длинны стены
	int setLenght(int x);
	//настройка направления стены
	int setDirection(way x);
	//направление стены(u/d/l/r)
	way getDirection();
	//чтобы были миленькеие углы :3
	bool isCorner();
private:
	int x, y;
	int height, width;
	int lenght;
	way direction;
};

