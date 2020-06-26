/*
Библиотека для работы с врагами игры.
Ширкунов А.В. ИВТ-13БО
*/
#pragma once
//варианты передвижения
enum CatWay
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
};
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
	//алгоритм преследования
	void MovesFunction();
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