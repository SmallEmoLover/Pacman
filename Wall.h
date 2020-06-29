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

	Wall(int x, int y, int width, int height, way direction, bool isCorner);
	//координата начала по Х
	int getX();
	//координата начала по У
	int getY();
	//ширина
	int getWidth();
	//высота
	int getHeight();
	//настройка ширины
	void setWidth(int width);
	//настройка высоты
	void setHeight(int height);
	//настройка направления стены
	int setDirection(way x);
	//направление стены(u/d/l/r)
	way getDirection();
private:
	way _direction;
	bool _isCorner;
};

