/*
	Вспомогательные функции
	Пакман
	Кулаков Д.С. ИВТ-13БО
	Ширкунов А.В. ИВТ-13БО
*/

#include "Util.h"

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

bool CollisionDetect(Player *player, Cat *cat)
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

//Вспомогательная функция отзеркаливания стены по оси Y
Wall* MirrorWall(Wall* src)
{
	Wall* result = new Wall(28 - src->getX() - src->getWidth(), src->getY(),
		src->getWidth(), src->getHeight());
	return result;
}

//Карта симметрична, поэтому мы можем создать лишь половину и отзеркалить
void CreateWalls(Wall* walls[WallCount])
{
	walls[0] = new Wall(13, 3, 1, 5);
	walls[1] = new Wall(0, 3, 13, 1);
	walls[2] = new Wall(0, 4, 1, 8);
	walls[3] = new Wall(0, 12, 6, 5);
	walls[4] = new Wall(0, 18, 6, 5);
	walls[5] = new Wall(0, 23, 1, 11);
	walls[6] = new Wall(1, 33, 13, 1);
	walls[7] = new Wall(1, 27, 2, 2);
	walls[8] = new Wall(2, 5, 4, 3);
	walls[9] = new Wall(7, 5, 5, 3);
	walls[10] = new Wall(2, 9, 4, 2);
	walls[11] = new Wall(7, 9, 2, 8);
	walls[12] = new Wall(9, 12, 3, 2);
	walls[13] = new Wall(10, 9, 4, 2);
	walls[14] = new Wall(13, 11, 1, 3);
	walls[15] = new Wall(7, 18, 2, 5);
	walls[16] = new Wall(10, 21, 4, 2);
	walls[17] = new Wall(13, 23, 1, 3);
	walls[18] = new Wall(7, 24, 5, 2);
	walls[19] = new Wall(2, 24, 4, 2);
	walls[20] = new Wall(4, 26, 2, 3);
	walls[21] = new Wall(7, 27, 2, 3);
	walls[22] = new Wall(2, 30, 10, 2);
	walls[23] = new Wall(10, 27, 4, 2);
	walls[24] = new Wall(13, 29, 1, 3);
	walls[25] = new Wall(10, 15, 4, 5);

	for (int i = 0; i < 26; i++)
		walls[i + 26] = MirrorWall(walls[i]);
}

bool IsWall(int x, int y, Wall* walls[WallCount])
{
	for (int i = 0; i < WallCount; i++)
	{
		if ((x >= walls[i]->getX()) && (x < walls[i]->getX() + walls[i]->getWidth())
			&& (y >= walls[i]->getY()) && (y < walls[i]->getY() + walls[i]->getHeight()))
			return true;
	}
	return false;
}