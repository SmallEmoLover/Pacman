/*
Библиотека работы с врагами
Ширкунов А.В. ИВТ-13БО
*/
#pragma once

#include "Object.h"
#include "Util.h"

class Wall;

class Cat : public Object
{
	public:
		Cat(int x_block, int y_block);
		//алгоритм передвижения врага
		void AIMove(int Px, int Py, int step, Wall* walls[WallCount]);
		//движение вверх
		void MoveUp(int step);
		//движение вниз
		void MoveDown(int step);
		//движение вправо
		void MoveRight(int step);
		//движение влево
		void MoveLeft(int step);
		void setX(int x);
		void setY(int y);
};