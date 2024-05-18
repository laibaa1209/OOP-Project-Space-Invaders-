#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Bullet : public Drawable
{
private:
	Sprite bulletSprite;
	int bulletSpeed;


public:
	Bullet();
	Bullet(int x, int y, Texture& bulletTexture, IntRect intRect, int bulletSpeed);
	void update();
	Vector2f getPosition();
	virtual void draw(RenderTarget &rt, RenderStates rs) const;
};