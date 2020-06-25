/*
Библиотека для работы с главным героем игры Пакман
Дорофеев Д.Г. ИВТ-13БО
*/
#pragma once
#include"Object.h"
class Player : public Object
{
public:
	//Конструктор по умолчанию
	Player();
	//координата по Х
	int getX();

	//координата по У
	int getY();

	//настройка ширины
	int setWidth();

	//настройка высоты
	int setHight();

	//статус пылесоса(движение/бонусное движение/простой на месте)
	int status();

	//изменение статуса(движение/бонусное движение/простой на месте)
	int changeStatus(int x);

	//движение вверх
	int up(int x);

	//движение вниз
	int down(int x);

	//движение вправо
	int right(int x);

	//движение в лево
	int left(int x);

	//направление движения на данный момент(u/d/r/l)
	char direction();

private:
	int x, y;
	int widht, height;
	int status;
	char direction;
};

