/*
Библиотека для работы с врагами игры.
Ширкунов А.В. ИВТ-13БО
*/
#pragma once
#include "Player.h"
#include "Object.h"

//режимы врагов
enum CatMode
{
	//преследование
	CHASE,
	//побег
	RUNAWAY,
	//ожидание выхода
	WAITING,
	//возвращение в точку ожидания
	RETURN,
};
class Cats : public Object
{
	public:
		//алгоритм передвижения
		way AIMove();
		//Узнать статус (преследует/убегает/ждет выхода/возвращается на вход)
		CatMode getStatus();
		//Изменить статус (преследует/убегает/ждет выхода/возвращается на вход)
		void setStatus(CatMode x);
		//координата начала по Х
		int getX();
		//координата начала по У
		int getY();
		//движение вверх
		int MoveUp(int step);
		//движение вниз
		int MoveDown(int step);
		//движение вправо
		int MoveRight(int step);
		//движение влево
		int MoveLeft(int step);

	private:
		//Статус (преследует/убегает/ждет выхода/возвращается на вход)
		CatMode status;
};