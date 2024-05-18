#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Wall : public Drawable
{
private:
	vector<Sprite> sprites;
	vector<pair<int, int>> state;

public:
	Wall(int x, int y, Texture& wallTexture);
	void getPosition(vector<pair<int, Vector2f>> &pos);
	void update();
	void collision(int indice, bool up);
	virtual void draw(RenderTarget &rt, RenderStates rs) const;
};