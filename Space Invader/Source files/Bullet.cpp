#include "Bullet.h"

Bullet::Bullet(int x, int y, Texture& bulletTexture, IntRect intRect, int bulletSpeed)
{
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setTextureRect(intRect);
	bulletSprite.setPosition(x, y);
	bulletSprite.setScale(3, 3);
	this->bulletSpeed = bulletSpeed;
}

Bullet::Bullet()
{

}

void Bullet::update()
{
	bulletSprite.move(0, bulletSpeed);
}

Vector2f Bullet::getPosition()
{
	return bulletSprite.getPosition();
}

void Bullet::draw(RenderTarget &rt, RenderStates rs) const
{
	rt.draw(bulletSprite);
}