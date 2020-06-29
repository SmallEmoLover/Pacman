#include"Player.h"
Player::Player() 
{
	_status = CLASSIC;
	_direction = UP;
	_step = 1;
	_powerCoefficient = 2;
}
way Player::getDirection() 
{
	return _direction;
}
mode Player::getStatus()
{
	return _status;
}
void Player::setStatus(mode status) 
{
	_status = status;
}
void Player::setDirection(way direction)
{
	_direction = direction;
}

int Player::getHeight()
{
	return _height;
}

int Player::getWidth()
{
	return _width;
}

int Player::moveLeft()
{
	//���� ��������
	if (_x - _step/*�� ������*/ && _status == CLASSIC)
	{
		_x -= _step;
		return 1;
	}
	if (_x - _step/*�� ������*/ && _status == POWER)
	{
		_x -= _step * _powerCoefficient;
		return 1;
	}
	return 0;
}
int Player::moveRight()
{
	//���� ��������
	if (_x + _step/*�� ������*/ && _status == CLASSIC) 
	{
		_x += _step;
		return 1;
	}
	if (_x + _step/*�� ������*/ && _status == POWER) 
	{
		_x += _step * _powerCoefficient;
		return 1;
	}
	return 0;
}
int Player::moveUp()
{
	//���� ��������
	if (_y + _step/*�� ������*/ && _status == CLASSIC) 
	{
		_y += _step;
		return 1;
	}
	if (_y + _step/*�� ������*/ && _status == POWER) 
	{
		_y += _step * _powerCoefficient;
		return 1;
	}
	return 0;
}
int Player::moveDown()
{
	//���� ��������
	if (_y - _step/*�� ������*/ && _status == CLASSIC)
	{
		_y -= _step;
		return 1;
	}
	if (_y - _step/*�� ������*/ && _status == POWER) 
	{
		_y -= _step * _powerCoefficient;
		return 1;
	}
	return 0;
}