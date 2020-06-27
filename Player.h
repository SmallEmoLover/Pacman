/*
���������� ��� ������ � ������� ������ ���� ������
�������� �.�. ���-13��
*/
#pragma once
#include"Object.h"
#include"Game.h"
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
	int Object::getX();
	//���������� �� �
	int Object::getY();
	//����������� �������� �� ������ ������(u/d/r/l)
	way getDirection();
	//������ ��������(��������/�������� ��������/������� �� �����)
	mode getStatus();
	//��������� ������
	int Object::setWidth();
	//��������� ������
	int Object::setHeight();
	//��������� ����������� ��������
	void setDirection(way x);
	//��������� �������(��������/�������� ��������/������� �� �����)
	void setStatus(mode x);
	//�������� �����
	int moveUp();
	//�������� ����
	int moveDown();
	//�������� ������
	int moveRight();
	//�������� � ����
	int moveLeft();
private:
	mode status;
	way direction;
	int step;
	int Object::x, y;
	int Object::height, width;
	int powerCoefficient;
};

