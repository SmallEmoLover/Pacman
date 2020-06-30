#include"Player.h"

Player::Player() 
{
	_status = CLASSIC;
	_step = 1;
	_powerCoefficient = 2;
}

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
		_y += _step;
	else
		_y += _step * _powerCoefficient;
}

void Player::moveDown()
{
	if (_status == CLASSIC)
		_y -= _step;
	else
		_y -= _step * _powerCoefficient;
}