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
	//настройка Х
	void setX(int x);
	//настройка У
	void setY(int y);
	//движение вверх
	void moveUp();
	//движение вниз
	void moveDown();
	//движение вправо
	void moveRight();
	//движение в лево
<<<<<<< HEAD
	int moveLeft();
	//функция смены направления
	int move(way direction);
=======
	void moveLeft();
>>>>>>> dfd539d1f1bdecdc6ef9c023175332ac6f01d8cc
private:
	mode _status;
	way _direction;
	int _step;
	int _powerCoefficient;
};

