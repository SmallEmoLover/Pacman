/*
���������� ��� ������ � ����������� ����������.
�������� �.�. ���-13��
*/
#pragma once
class Rubbish : public Object
{
	public:
		//���������� ������ �� �
		int getX();
		//���������� ������ �� �
		int getY();
		//������ (������/�� ������)
		bool IsCollected();
}