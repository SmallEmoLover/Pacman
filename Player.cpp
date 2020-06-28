#include"Player.h"
Player::Player() 
{
	status = CLASSIC;
	direction = UP;
	step = 1;
	x = 0;
	y = 0;
	powerCoefficient = 2;
}
way Player::getDirection() 
{
	return direction;
}
mode Player::getStatus()
{
	return status;
}
void Player::setStatus(mode x) 
{
	status = x;
}
void Player::setDirection(way x)
{
	direction = x;
}

int Player::getHeight()
{
	return height;
}

int Player::getWidth()
{
	return width;
}

int Player::moveLeft()
{
	//���� ��������
	if (x - step/*�� ������*/ && status == CLASSIC)
	{
		x -= step;
		return 1;
	}
	if (x - step/*�� ������*/ && status == POWER)
	{
		x -= step * powerCoefficient;
		return 1;
	}
	return 0;
}
int Player::moveRight()
{
	//���� ��������
	if (x + step/*�� ������*/ && status == CLASSIC) 
	{
		x += step;
		return 1;
	}
	if (x + step/*�� ������*/ && status == POWER) 
	{
		x += step * powerCoefficient;
		return 1;
	}
	return 0;
}
int Player::moveUp()
{
	//���� ��������
	if (y + step/*�� ������*/ && status == CLASSIC) 
	{
		y += step;
		return 1;
	}
	if (y + step/*�� ������*/ && status == POWER) 
	{
		y += step * powerCoefficient;
		return 1;
	}
	return 0;
}
int Player::moveDown()
{
	//���� ��������
	if (y - step/*�� ������*/ && status == CLASSIC)
	{
		y -= step;
		return 1;
	}
	if (y - step/*�� ������*/ && status == POWER) 
	{
		y -= step * powerCoefficient;
		return 1;
	}
	return 0;
}