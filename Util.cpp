/*
	Вспомогательные функции
	Пакман
	Кулаков Д.С. ИВТ-13БО
	Ширкунов А.В. ИВТ-13БО
*/

#include "Util.h"
#define WallCount 40

//Основано на разности Минковского с учётом того, что все хитбоксы - прямоугольники
bool CollisionDetect(int x11, int x12, int y11, int y12, int x21, int x22, int y21, int y22)
{
	if (x11 - x21 > 0 && x11 - x22 > 0 && x12 - x21 > 0 && x12 - x22 > 0) 
		return false;
	if (x11 - x21 < 0 && x11 - x22 < 0 && x12 - x21 < 0 && x12 - x22 < 0)
		return false;
	if (y11 - y21 > 0 && y11 - y22 > 0 && y12 - y21 > 0 && y12 - y22 > 0)
		return false;
	if (y11 - y21 < 0 && y11 - y22 < 0 && y12 - y21 < 0 && y12 - y22 < 0)
		return false;

	return true;
}

bool CollisionDetect(Player *player, Cats *cat)
{
	int x11 = player->getX();
	int x12 = x11 + player->getWidth();
	int y11 = player->getY();
	int y12 = y11 + player->getHeight();

	int x21 = cat->getX();
	int x22 = x21 + cat->getWidth();
	int y21 = cat->getY();
	int y22 = x21 + cat->getHeight();

	return CollisionDetect(x11, x12, y11, y12, x21, x22, y21, y22);
}

bool CollisionDetect(Player *player, Rubbish *rubbish)
{
	int x11 = player->getX();
	int x12 = x11 + player->getWidth();
	int y11 = player->getY();
	int y12 = y11 + player->getHeight();

	int x21 = rubbish->getX();
	int x22 = x21 + rubbish->getWidth();
	int y21 = rubbish->getY();
	int y22 = x21 + rubbish->getHeight();

	return CollisionDetect(x11, x12, y11, y12, x21, x22, y21, y22);
}