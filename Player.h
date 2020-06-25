/*
���������� ��� ������ � ������� ������ ���� ������
�������� �.�. ���-13��
*/
#pragma once
#include"Object.h"
class Player : public Object
{
public:
	//����������� �� ���������
	Player();
	//���������� �� �
	int getX();

	//���������� �� �
	int getY();

	//��������� ������
	int setWidth();

	//��������� ������
	int setHight();

	//������ ��������(��������/�������� ��������/������� �� �����)
	int status();

	//��������� �������(��������/�������� ��������/������� �� �����)
	int changeStatus(int x);

	//�������� �����
	int up(int x);

	//�������� ����
	int down(int x);

	//�������� ������
	int right(int x);

	//�������� � ����
	int left(int x);

	//����������� �������� �� ������ ������(u/d/r/l)
	char direction();

private:
	int x, y;
	int widht, height;
	int status;
	char direction;
};

