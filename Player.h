/*
Библиотека для работы с главным героем игры Пакман
Дорофеев Д.Г. ИВТ-13БО
*/
#pragma once
#include"Object.h"
#include"Game.h"
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
	//ширина
	int getWidth();
	//высота
	int getHeight();
	//настройка ширины
	void setWidth(int width);
	//настройка высоты
	void setHeight(int height);
	//изменение направления движения
	void setDirection(way x);
	//изменение статуса(движение/бонусное движение/простой на месте)
	void setStatus(mode x);
	//движение вверх
	int moveUp();
	//движение вниз
	int moveDown();
	//движение вправо
	int moveRight();
	//движение в лево
	int moveLeft();
private:
	mode _status;
	way _direction;
	int _step;
	int _powerCoefficient;
};

