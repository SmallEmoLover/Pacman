/*
Библиотека для работы с собираемыми элементами.
Ширкунов А.В. ИВТ-13БО
*/
#pragma once
class Rubbish : public Object
{
public:
	//координата начала по Х
	int getX();
	//координата начала по У
	int getY();
private:
	//статус (собран/не собран)
	bool IsCollected();
}