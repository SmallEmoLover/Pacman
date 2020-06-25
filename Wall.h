/*
���������� ��� ������ � ������������ ����
������
�������� �.�. ���-13��
*/
#pragma once
#include"Object.h"
enum Way
{
	up,
	down,
	right,
	left
};
class Wall : public Object
{
public:
	Wall();
	//���������� ������ �� �
	int getX();
	//���������� ������ �� �
	int getY();
	//��������� ������ ������ ������
	int setWidth();
	//��������� ������ ������ ������
	int setHight();
	//��������� ������ �����
	int setLenght();
	//��������� ����������� �����
	int setDirection();
	//����������� �����(u/d/l/r)
	Way getDirection();
private:
	int x, y;
	int widht, height;
	int lenght;
	Way direction;
};

