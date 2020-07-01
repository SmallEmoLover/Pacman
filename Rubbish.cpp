#include "Rubbish.h"

//возвращает _IsColected (собран элемент/не собран)
bool Rubbish::getIsCollected()
{
	return _IsCollected;
}

//изменить _IsColected
void Rubbish::setIsCollected(bool value)
{
	_IsCollected = true;
}
