/*
Библиотека для работы с главным героем игры Пакман
Дорофеев Д.Г. ИВТ-13БО
*/
#pragma once
#include "Object.h"
#include "Wall.h"
#include "Util.h"

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
		//статус пылесоса(движение/бонусное движение/простой на месте)
		mode getStatus();
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
		//движение влево
		void moveLeft();
		//функция движения
		void move(Wall *walls[WallCount]);
	private:
		mode _status;
		way _direction;
		int _step;
		int _powerCoefficient;
};

