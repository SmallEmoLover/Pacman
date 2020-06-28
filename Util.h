/*
	Библиотека вспомогательных функций
	Пакман
	Кулаков Д.С. ИВТ-13БО
	Ширкунов А.В. ИВТ-13БО
*/

#pragma once

#include "Cats.h"
#include "Player.h"
#include "Rubbish.h"
#include "Wall.h"

//Столкнулись ли объекты
bool CollisionDetect(int x11, int x12, int y11, int y12, int x21, int x22, int y21, int y22);
bool CollisionDetect(Player *player, Cats *cat);
bool CollisionDetect(Player *player, Rubbish *rubbish);

//Расставление стен
Wall* CreateWalls();

//Расставление собираемых объектов
Rubbish* CreateRubbish();

//Проверка на то, является ли координата стеной
bool IsWall(int x, int y);