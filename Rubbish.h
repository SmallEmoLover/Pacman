/*
���������� ��� ������ � ����������� ����������.
�������� �.�. ���-13��
*/
#pragma once
#include "Object.h"
#include"Player.h"

class Rubbish : public Object
{
public:
	//���������� �� �
	int getX();
	//���������� �� �
	int getY();
	//ширина
	int getWidth();
	//высота
	int getHeight();
	//�������� IsColected (������ �������/�� ������)
	bool getIsCollected();
	//�������� IsColected
	void setIsCollected(bool value);
private:
	//������ (������/�� ������)
	bool IsCollected;
};