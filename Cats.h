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
	CHASE,
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
		//������ ������ (����������/�������/���� ������/������������ �� ����)
		CatMode getStatus();
		//�������� ������ (����������/�������/���� ������/������������ �� ����)
		void setStatus(CatMode x);
		//���������� ������ �� �
		int getX();
		//���������� ������ �� �
		int getY();
		//�������� �����
		int MoveUp(int step);
		//�������� ����
		int MoveDown(int step);
		//�������� ������
		int MoveRight(int step);
		//�������� �����
		int MoveLeft(int step);

	private:
		//������ (����������/�������/���� ������/������������ �� ����)
		CatMode status;
};