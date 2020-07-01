#include"Player.h"

Player::Player() 
{
	_status = CLASSIC;
	_step = 2;
	_powerCoefficient = 2;
	_x = 14 * PixInBlock;
	_y = 26 * PixInBlock;
	_width = PixInBlock;
	_height = PixInBlock;
	_direction = LEFT;
}

void Player::setX(int x)
{
	_x = x;
}
void Player::setY(int y)
{
	_y = y;
}
mode Player::getStatus()
{
	return _status;
}
void Player::setStatus(mode status) 
{
	_status = status;
}

void Player::moveLeft()
{
	if (_status == CLASSIC)
		_x -= _step;
	else
		_x -= _step * _powerCoefficient;
	if (_x < -PixInBlock)
		_x = 28 * PixInBlock;
}

void Player::moveRight()
{
	if (_status == CLASSIC)
		_x += _step;
	else
		_x += _step * _powerCoefficient;
	if (_x > 28 * PixInBlock)
		_x = -PixInBlock;
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

void Player::move(Wall *walls[WallCount])
{
	if (!IsWall(this, walls, _direction))
	{
		switch (_direction)
		{
			case UP:
				moveUp();
				break;
			case DOWN:
				moveDown();
				break;
			case RIGHT:
				moveRight();
				break;
			case LEFT:
				moveLeft();
				break;
		}
	}
}

void Player::setDirection(way direction)
{
	_direction = direction;
}