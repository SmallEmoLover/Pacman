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
	int Object::getX();
	//координата начала по У
	int Object::getY();
	//настройка ширины одного кубика
	int Object::setWidth();
	//настройка высоты одного кубика
	int Object::setHeight();
	//получение длинны стены
	int getLenght();
	//настройка длинны стены
	int setLenght(int x);
	//настройка направления стены
	int setDirection(way x);
	//направление стены(u/d/l/r)
	way getDirection();
private:
	int Object::x, y;
	int Object::height, width;
	int lenght;
	way direction;
};

