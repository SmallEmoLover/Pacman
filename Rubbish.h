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
	//�������� IsColected (������ �������/�� ������)
	bool getIsCollected();
	//�������� IsColected
	void setIsCollected(bool value);
private:
	//������ (������/�� ������)
	bool _IsCollected;
};