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

class Player : public Object
{
	public:
		//Конструктор по умолчанию
		Player();
		//изменение направления движения
		void setDirection(way x);
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
		way _direction;
		int _step;
};

