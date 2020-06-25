/*
���������� ��� ������ � ������� ������ ���� ������
�������� �.�. ���-13��
*/
#pragma once
#include"Object.h"
enum way
{
	up,
	down,
	right,
	left,
};
enum mode 
{
	classic,
	power,
};
class Player : public Object
{
public:
	//����������� �� ���������
	Player();
	//���������� �� �
	int getX();
	//���������� �� �
	int getY();
	//����������� �������� �� ������ ������(u/d/r/l)
	way getDirection();
	//������ ��������(��������/�������� ��������/������� �� �����)
	mode getStatus();
	//��������� ������
	int setWidth();
	//��������� ������
	int setHight();
	//��������� �������(��������/�������� ��������/������� �� �����)
	int setStatus(mode x);
	//�������� �����
	int muveUp();
	//�������� ����
	int moveDown();
	//�������� ������
	int moveRight();
	//�������� � ����
	int moveLeft(int x);
private:
	int x, y;
	int widht, height;
	mode status;
	way direction;
};

