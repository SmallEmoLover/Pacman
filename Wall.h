#pragma once
class Wall : public Object
{
public:
	Wall();
	//координата начала по Х
	int getX();

	//координата начала по У
	int getY();

	//настройка ширины одного кубика
	int setWidth();

	//настройка высоты одного кубика
	int setHight();

	//настройка длинны стены
	int setLenght();

	//настройка направления стены
	int setDirection();

	//направление стены(u/d/l/r)
	char direction();

private:
	int x, y;
	int widht, height;
	int lenght;
	char direction;
};

