#include"Player.h"

Player::Player() 
{
	_step = 2;
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

void Player::moveLeft()
{
	_x -= _step;
	if (_x < -PixInBlock)
		_x = 28 * PixInBlock;
}

void Player::moveRight()
{
	_x += _step;
	if (_x > 28 * PixInBlock)
		_x = -PixInBlock;
}

void Player::moveUp()
{
	_y -= _step;
}

void Player::moveDown()
{
	_y += _step;
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