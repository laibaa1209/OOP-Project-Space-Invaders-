#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"

using namespace std;
using namespace sf;

class Player : public Drawable
{
private:
	Sprite playerSprite;
	int numberOfLives;
	int playerSpeed;
	bool shooting = false;


public:
	Player(int x, int y, Texture &playerTexture);
	void update();
	bool shoot();
	Vector2f getPosition();
	void reduceLives();
	bool isDead();
	virtual void draw(RenderTarget &rt, RenderStates rs) const;
};