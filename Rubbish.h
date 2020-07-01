/*
	Класс для работы с собираемыми объектами
	Ширкунов А.В. ИВТ-13БО
*/

#pragma once
#include "Object.h"
#include"Player.h"

class Rubbish : public Object
{
	public:
		Rubbish(int x_block, int y_block);
		//возвращает IsColected (собран элемент/не собран)
		bool getIsCollected();
		//изменяет статус IsColected
		void setIsCollected(bool value);
	private:
		//статус (собран/не собран)
		bool _IsCollected;
};