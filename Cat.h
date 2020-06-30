/*
Библиотека работы с врагами
Ширкунов А.В. ИВТ-13БО
*/
#pragma once
#include "Player.h"
#include "Object.h"
#include "Util.h"

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
		//алгоритм передвижения врага
		way AIMove(int Px, int Py, int step, Wall* walls[WallCount]);
		//вернуть статус (преследует/убегает/ждет выхода/возвращается к выходу)  
		CatMode getStatus();
		//изменить статус (преследует/убегает/ждет выхода/возвращается к выходу)
		void setStatus(CatMode x);
		//координата по X
		int getX();
		//координата по У
		int getY();
		//ширина
		int getWidth();
		//высота
		int getHeight();
		//движение вверх
		int MoveUp(int step);
		//движение вниз
		int MoveDown(int step);
		//движение вправо
		int MoveRight(int step);
		//движение влево
		int MoveLeft(int step);

	private:
		//статус (преследует/убегает/ждет выхода/возвращается к выходу)
		CatMode _status;
};