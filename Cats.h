/*
���������� ��� ������ � ������� ����.
�������� �.�. ���-13��
*/
#pragma once
#include "Player.h"
#include "Object.h"

//������ ������
enum CatMode
{
	//�������������
	PURSUIT,
	//�����
	RUNAWAY,
	//�������� ������
	WAITING,
	//����������� � ����� ��������
	RETURN,
};
class Cats : public Object
{
	public:
		//�������� ������������
		way AIMove();
		//�������� ������ (����������/�������/���� ������/������������ �� ����)
		CatMode GetStatus();
		//���������� ������ �� �
		int getX();
		//���������� ������ �� �
		int getY();
		//�������� �����
		int MoveUp();
		//�������� ����
		int MoveDown();
		//�������� ������
		int MoveRight();
		//�������� �����
		int MoveLeft();

	private:
		//������ (����������/�������/���� ������/������������ �� ����)
		CatMode Status();
};