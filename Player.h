/*
Библиотека для работы с главным героем игры Пакман
Дорофеев Д.Г. ИВТ-13БО
*/
#pragma once
#include"Object.h"
enum way
{
	up,
	down,
	right,
	left,
};
enum mode 
{
	classic,
	power,
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
	int setHight();
	//изменение статуса(движение/бонусное движение/простой на месте)
	int setStatus(mode x);
	//движение вверх
	int muveUp();
	//движение вниз
	int moveDown();
	//движение вправо
	int moveRight();
	//движение в лево
	int moveLeft(int x);
private:
	int x, y;
	int widht, height;
	mode status;
	way direction;
};

