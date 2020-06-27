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

int Player::moveLeft()
{
	//Если возможно
	if (x - step/*не занято*/ && status == CLASSIC)
	{
		x -= step;
		return 1;
	}
	if (x - step/*не занято*/ && status == POWER)
	{
		x -= step * powerCoefficient;
		return 1;
	}
	return 0;
}
int Player::moveRight()
{
	//Если возможно
	if (x + step/*не занято*/ && status == CLASSIC) 
	{
		x += step;
		return 1;
	}
	if (x + step/*не занято*/ && status == POWER) 
	{
		x += step * powerCoefficient;
		return 1;
	}
	return 0;
}
int Player::moveUp()
{
	//Если возможно
	if (y + step/*не занято*/ && status == CLASSIC) 
	{
		y += step;
		return 1;
	}
	if (y + step/*не занято*/ && status == POWER) 
	{
		y += step * powerCoefficient;
		return 1;
	}
	return 0;
}
int Player::moveDown()
{
	//Если возможно
	if (y - step/*не занято*/ && status == CLASSIC)
	{
		y -= step;
		return 1;
	}
	if (y - step/*не занято*/ && status == POWER) 
	{
		y -= step * powerCoefficient;
		return 1;
	}
	return 0;
}