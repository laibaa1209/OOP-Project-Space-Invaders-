#include "Enemy.h"

Enemy::Enemy(int x, int y, Texture& enemyTexture, Vector2f point)
{
	this->point = point;
	enemySprite.setTexture(enemyTexture);
	enemySprite.setTextureRect(IntRect(point.x, point.y, 8, 8));
	enemySprite.setPosition(x, y);
	enemySprite.setScale(3, 3);
	state = 0;
	timer = 0;
	enemySpeed = 24;
	resetTimer = 100;
	m_PlayerExplodeBuffer.loadFromFile("sound/playerexplode.ogg");
}

void Enemy::update()
{
	if (timer >= resetTimer)
	{
		enemySprite.move(enemySpeed, 0);
		state++;
		state = state % 2; // state alternates 0 and 1
		enemySprite.setTextureRect(IntRect(point.x + state * 9, point.y, 8, 8));
		timer = 0;
	}
	timer++;
}

void Enemy::changeDirection()
{
	enemySpeed = -enemySpeed;
	enemySprite.move(0, abs(enemySpeed));
}

Vector2f Enemy::getPosition()
{
	return enemySprite.getPosition();
}

void Enemy::decreaseResetTimer()
{
	--resetTimer;
}

void Enemy::draw(RenderTarget &rt, RenderStates rs) const
{
	rt.draw(enemySprite, rs);
}