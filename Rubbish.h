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
	//�������� IsColected (������ �������/�� ������)
	bool getIsCollected();
	//�������� IsColected
	void setIsCollected(bool value);
private:
	//������ (������/�� ������)
	bool IsCollected;
	int Object::x, y;
};