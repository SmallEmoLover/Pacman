#include "Rubbish.h"

Rubbish::Rubbish(int x_block, int y_block)
{
	_x = x_block * PixInBlock;
	_y = y_block * PixInBlock;
	_width = PixInBlock;
	_height = PixInBlock;
	_IsCollected = false;
}

//возвращает _IsColected (собран элемент/не собран)
bool Rubbish::getIsCollected()
{
	return _IsCollected;
}

//изменить _IsColected
void Rubbish::setIsCollected(bool value)
{
	_IsCollected = value;
}
