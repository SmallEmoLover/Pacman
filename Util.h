/*
	Библиотека вспомогательных функций
	Пакман
	Кулаков Д.С. ИВТ-13БО
	Ширкунов А.В. ИВТ-13БО
*/

#pragma once

#define WallCount 52

#include "Cat.h"
#include "Player.h"
#include "Rubbish.h"
#include "Wall.h"

//Объявление классы дабы избежать ошибок
class Cat;
class Player;
class Wall;
class Rubbish;
enum way;

//Столкнулись ли объекты
bool CollisionDetect(Object *first, Object *second);
bool CollisionDetect(int x11, int x12, int y11, int y12, int x21, int x22, int y21, int y22);

//Расставление стен
void CreateWalls(Wall* walls[WallCount]);

//Расставление собираемых объектов
Rubbish* CreateRubbish();

//Есть ли в направлении direction стена вплотную
bool IsWall(Object *object, Wall* walls[WallCount], way direction);