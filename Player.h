/*
Библиотека для работы с главным героем игры Пакман
Дорофеев Д.Г. ИВТ-13БО
*/
#pragma once
#include "Object.h"

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
	//направление движения на данный момент(u/d/r/l)
	way getDirection();
	//статус пылесоса(движение/бонусное движение/простой на месте)
	mode getStatus();
	//настройка ширины
	void setWidth(int width);
	//настройка высоты
	void setHeight(int height);
	//изменение направления движения
	void setDirection(way x);
	//изменение статуса(движение/бонусное движение/простой на месте)
	void setStatus(mode x);
	//движение вверх
	void moveUp();
	//движение вниз
	void moveDown();
	//движение вправо
	void moveRight();
	//движение в лево
	void moveLeft();
private:
	mode _status;
	way _direction;
	int _step;
	int _powerCoefficient;
};

