/*
	Класс для работы с расстановкой стен
	Пакман
	Дорофеев Д.Г. ИВТ-13БО
*/

#pragma once

#include"Object.h"
#include"Player.h"

class Wall : public Object
{
	public:
		Wall();
		//конструктор класса
		Wall(int x, int y, int width, int height);
};

