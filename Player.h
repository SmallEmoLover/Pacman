/*
Библиотека для работы с главным героем игры Пакман
Дорофеев Д.Г. ИВТ-13БО
*/
#pragma once
#include"Object.h"
enum way
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
};
enum mode 
{
	CLASSIC,
	POWER,
};
class Player : public Object
{
public:
	//Конструктор по умолчанию
	Player();
	//координата по Х
	int getX();
	//координата по У
	int getY();
	//направление движения на данный момент(u/d/r/l)
	way getDirection();
	//статус пылесоса(движение/бонусное движение/простой на месте)
	mode getStatus();
	//настройка ширины
	int setWidth();
	//настройка высоты
	int setHeight();
	//изменение статуса(движение/бонусное движение/простой на месте)
	int setStatus(mode x);
	//движение вверх
	int muveUp();
	//движение вниз
	int muveDown();
	//движение вправо
	int muveRight();
	//движение в лево
	int muveLeft(int x);
private:
	mode status;
	way direction;
};

