#include"Player.h"

Player::Player() 
{
	_status = CLASSIC;
	_step = 1;
	_powerCoefficient = 2;
}
<<<<<<< HEAD
void Player::setX(int x)
{
	_x = x;
}
void Player::setY(int y)
{
	_y = y;
}
=======

>>>>>>> dfd539d1f1bdecdc6ef9c023175332ac6f01d8cc
mode Player::getStatus()
{
	return _status;
}

void Player::setStatus(mode status) 
{
	_status = status;
}

//необходимо дописать условия возможности движения
void Player::moveLeft()
{
	if (_status == CLASSIC)
		_x -= _step;
	else
		_x -= _step * _powerCoefficient;
}

void Player::moveRight()
{
	if (_status == CLASSIC)
		_x += _step;
	else
		_x += _step * _powerCoefficient;
}

void Player::moveUp()
{
	if (_status == CLASSIC)
		_y -= _step;
	else
		_y -= _step * _powerCoefficient;
}

void Player::moveDown()
{
	if (_status == CLASSIC)
		_y += _step;
	else
		_y += _step * _powerCoefficient;
}
int Player::move(way direction)
{
	switch(direction)
	{
	case UP:
		while(1)
			moveUp();
		break;
	case DOWN:
		while (1)
			moveDown();
		break;
	case RIGHT:
		while (1)
			moveRight();
		break;
	case LEFT:
		while (1)
			moveLeft();
		break;
	}
}