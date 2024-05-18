#include "Player.h"

Player::Player(int x, int y, Texture& playerTexture)
{
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(IntRect(13 * 8 + 8, 7 * 8 + 7, 16, 8)); // IntRect(left, top, width, height)
	playerSprite.setPosition(x, y);
	playerSprite.setScale(3, 3);
	numberOfLives = 3;
	playerSpeed = 5;
	

}

void Player::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Right) && playerSprite.getPosition().x + playerSpeed < 552)
	{
		playerSprite.move(playerSpeed, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Left) && playerSprite.getPosition().x - playerSpeed > 0)
	{
		playerSprite.move(-playerSpeed, 0);
	}
}

Vector2f Player::getPosition()
{
	return playerSprite.getPosition();
}

bool Player::shoot()
{
	if (Keyboard::isKeyPressed(Keyboard::Space) && !shooting)
	{
		shooting = true;
		return true;
	}

	else if (!Keyboard::isKeyPressed(Keyboard::Space))
	{
		shooting = false;
	}

	return false;
}

void Player::reduceLives()
{
	--numberOfLives;
}

bool Player::isDead()
{
	return !(numberOfLives > 0);
}

void Player::draw(RenderTarget& rt, RenderStates rs) const
{
	rt.draw(playerSprite, rs);
}

