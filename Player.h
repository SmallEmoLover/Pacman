/*
���������� ��� ������ � ������� ������ ���� ������
�������� �.�. ���-13��
*/
#pragma once
#include"Object.h"
enum way
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
};
enum mode 
{
	CLASSIC,
	POWER,
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
	int setHeight();
	//��������� �������(��������/�������� ��������/������� �� �����)
	int setStatus(mode x);
	//�������� �����
	int moveUp();
	//�������� ����
	int moveDown();
	//�������� ������
	int moveRight();
	//�������� � ����
	int moveLeft(int x);
private:
	mode status;
	way direction;
};

