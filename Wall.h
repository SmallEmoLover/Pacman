/*
���������� ��� ������ � ������������ ����
������
�������� �.�. ���-13��
*/
#pragma once
#include"Object.h"
#include"Player.h"
class Wall : public Object
{
public:
	Wall();
	//���������� ������ �� �
	int Object::getX();
	//���������� ������ �� �
	int Object::getY();
	//��������� ������ ������ ������
	int Object::setWidth();
	//��������� ������ ������ ������
	int Object::setHeight();
	//��������� ������ �����
	int getLenght();
	//��������� ������ �����
	int setLenght(int x);
	//��������� ����������� �����
	int setDirection(way x);
	//����������� �����(u/d/l/r)
	way getDirection();
private:
	int Object::x, y;
	int Object::height, width;
	int lenght;
	way direction;
};

