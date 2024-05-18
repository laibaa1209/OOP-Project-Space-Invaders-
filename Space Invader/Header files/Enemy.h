#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Enemy : public Drawable
{
private:
	Sprite enemySprite;
	int state;
	int timer;
	int resetTimer;
	Vector2f point;
	int enemySpeed;
	SoundBuffer m_PlayerExplodeBuffer;
	Sound m_PlayerExplodeSound;


public:
	Enemy(int x, int y, Texture& enemyTexture, Vector2f point);
	void update();
	void changeDirection();
	Vector2f getPosition();
	void decreaseResetTimer();
	virtual void draw(RenderTarget &rt, RenderStates rs) const;
};
