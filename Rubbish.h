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
	Rubbish(int x_block, int y_block);
	//�������� IsColected (������ �������/�� ������)
	bool getIsCollected();
	//�������� IsColected
	void setIsCollected(bool value);
private:
	//������ (������/�� ������)
	bool _IsCollected;
};