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
	int lenght;
	Way direction;
};

