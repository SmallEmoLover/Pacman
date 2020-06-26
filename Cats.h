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
	PURSUIT,
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
		//координата начала по Х
		int getX();
		//координата начала по У
		int getY();
		//движение вверх
		int MoveUp();
		//движение вниз
		int MoveDown();
		//движение вправо
		int MoveRight();
		//движение влево
		int MoveLeft();

	private:
		//Статус (преследует/убегает/ждет выхода/возвращается на вход)
		CatMode GetStatus();
};