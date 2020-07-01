/*
Библиотека работы с врагами
Ширкунов А.В. ИВТ-13БО
*/
#pragma once

#include "Wall.h"
#include "Object.h"
#include "Util.h"

class Wall;

//режимы врагов
enum CatMode
{
	//преследование
	CHASE,
	//побег
	RUNAWAY,
	//ожидание выхода
	WAITING,
	//возвращение к выходу
	RETURN,
};

class Cat : public Object
{
	public:
		Cat(int x_block, int y_block);
		//алгоритм передвижения врага
		way AIMove(int Px, int Py, int step, Wall* walls[WallCount]);
		//вернуть статус (преследует/убегает/ждет выхода/возвращается к выходу)  
		CatMode getStatus();
		//изменить статус (преследует/убегает/ждет выхода/возвращается к выходу)
		void setStatus(CatMode x);
		//движение вверх
		void MoveUp(int step);
		//движение вниз
		void MoveDown(int step);
		//движение вправо
		void MoveRight(int step);
		//движение влево
		void MoveLeft(int step);

	private:
		//статус (преследует/убегает/ждет выхода/возвращается к выходу)
		CatMode _status;
};