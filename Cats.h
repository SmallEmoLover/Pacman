/*
���������� ��� ������ � ������� ����.
�������� �.�. ���-13��
*/
#pragma once
//�������� ������������
enum CatWay
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
};
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
	//�������� �������������
	void MovesFunction();
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
		CatMode GetStatus();
};