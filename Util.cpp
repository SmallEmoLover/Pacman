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
	if ((x11 - x21 >= 0) && (x11 - x22 >= 0) && (x12 - x21 >= 0) && (x12 - x22 >= 0)) 
	return false;
	if ((x11 - x21 <= 0) && (x11 - x22 <= 0) && (x12 - x21 <= 0) && (x12 - x22 <= 0))
		return false;
	if ((y11 - y21 >= 0) && (y11 - y22 >= 0) && (y12 - y21 >= 0) && (y12 - y22 >= 0))
		return false;
	if ((y11 - y21 <= 0) && (y11 - y22 <= 0) && (y12 - y21 <= 0) && (y12 - y22 <= 0))
		return false;

	return true;
}

bool CollisionDetect(Object *first, Object *second)
{
	int x11 = first->getX();
	int x12 = x11 + first->getWidth();
	int y11 = first->getY();
	int y12 = y11 + first->getHeight();

	int x21 = second->getX();
	int x22 = x21 + second->getWidth();
	int y21 = second->getY();
	int y22 = y21 + second->getHeight();

	return CollisionDetect(x11, x12, y11, y12, x21, x22, y21, y22);
}

//Вспомогательная функция отзеркаливания стены по оси Y
Wall* MirrorWall(Wall* src)
{
	Wall* result = new Wall(28 - (src->getX() + src->getWidth()) / PixInBlock, src->getY() / PixInBlock,
		src->getWidth() / PixInBlock, src->getHeight() / PixInBlock);
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

bool IsWall(Object *object, Wall* walls[WallCount], way direction)
{
	//Создадим темповый объект, сместим его на 1 в нужном направлении и проверим на коллизию
	Player *tmp = new Player();
	switch (direction)
	{
		case UP:
			tmp->setX(object->getX());
			tmp->setY(object->getY() - 1);
			break;
		case DOWN:
			tmp->setX(object->getX());
			tmp->setY(object->getY() + 1);
			break;
		case LEFT:
			tmp->setX(object->getX() - 1);
			tmp->setY(object->getY());
			break;
		case RIGHT:
			tmp->setX(object->getX() + 1);
			tmp->setY(object->getY());
			break;
	}

	for (int i = 0; i < WallCount; i++)
	{
		if (CollisionDetect(tmp, walls[i]))
		{
			delete tmp;
			return true;
		}
	} 
	delete tmp;
	return false;
}

void CreateRubbish(Wall* walls[WallCount], Rubbish* rubbish[RubbishCount])
{
	bool wall = false;
	int num = 0;
	Player *player = new Player();
	for (int x = 1; x < 27; x++)
	{
		for (int y = 4; y < 33; y++)
		{
			if (x >= 7 && x <= 20 && y >=12 && y <= 22)
				continue;

			player->setX(x * PixInBlock);
			player->setY(y * PixInBlock);

			wall = false;

			for (int i = 0; i < WallCount; i++)
				if (CollisionDetect(player, walls[i]))
					wall = true;
			if (!wall)
			{
				rubbish[num] = new Rubbish(x, y);
				num++;
			}
		}
	}
}
