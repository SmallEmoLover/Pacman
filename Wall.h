/*
���������� ��� ������ � ������������ ����
������
�������� �.�. ���-13��
*/
#pragma once
#include"Object.h"
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
	char direction();

private:
	int x, y;
	int widht, height;
	int lenght;
	char direction;
};

