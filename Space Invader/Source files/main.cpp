#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <time.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Wall.h"

using namespace std;
using namespace sf;

void updatePlayer(Player &player, Bullet &bulletPlayer);
void updateBulletPlayer(Bullet &bulletPlayer, vector<vector<Enemy>> &enemies);
void updateEnemies(vector<vector<Enemy>> &enemies);
void updateBulletsEnemies(Player &player);
void updateWall(vector<Wall> &muro, Bullet &bulletPlayer);

Texture spritesheet;

int timer = 0;
int resetTimer = 125;

int enemyDirection = 1;
int maxX, minX;
int numberOfEnemies;

vector<Bullet> bulletsEnemies;

vector<pair<int, Vector2f>> positionWall;

Vector2f sectionSpritesheet;

IntRect playerRect;
IntRect bulletRect;
IntRect enemyRect;
IntRect wallRect;

bool bulletActive = false;

int main()
{

	SoundBuffer m_backgroundBuffer;
	m_backgroundBuffer.loadFromFile("sound/backgroundmusic.mp3");
	Sound m_backgroundSound;

	spritesheet.loadFromFile("graphics/spritesheet.png");
	Player player(288, 555, spritesheet);
	Bullet bulletPlayer(0, 0, spritesheet, IntRect(0, 0, 0, 0), 0);
	vector<vector<Enemy>> enemies(7, vector<Enemy>(12, Enemy(0, 0, spritesheet, Vector2f(0, 0))));
	for (int i = 0; i < (int)enemies.size(); i++) {
		for (int j = 0; j < (int)enemies[i].size(); j++) {
			if (i == 0) {
				sectionSpritesheet = Vector2f(0, 0);
			}
			else if (i < 3) {
				sectionSpritesheet = Vector2f(0, 9 + (8 * 4 + 4));
			}
			else if (i < 5) {
				sectionSpritesheet = Vector2f(0, 18 + (8 * 4 + 4) * 2);
			}
			else if (i < 7) {
				sectionSpritesheet = Vector2f(0, 27 + (8 * 4 + 4) * 3);
			}
			enemies[i][j] = Enemy(j * 30 + 24, i * 30 + 24, spritesheet, sectionSpritesheet);
		}
	}

	vector<Wall> wall(3, Wall(0, 0, spritesheet));

	for (int i = 0; i < 3; i++) {
		wall[i] = Wall(70 + 200 * i, 460, spritesheet);
	}


	RenderWindow window(VideoMode(600, 600), "Space Invaders");
	window.setFramerateLimit(60);

	sf::Music music;
	music.openFromFile("sound/bg2.mp3");
	// Set the music to loop
		music.setLoop(true);

		// Play the music
		music.play();

	while (window.isOpen() && music.getStatus() == sf::SoundSource::Playing) {

		//m_backgroundSound.play();
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();
		}

		updatePlayer(player, bulletPlayer);

		updateBulletPlayer(bulletPlayer, enemies);

		updateEnemies(enemies);

		updateBulletsEnemies(player);

		updateWall(wall, bulletPlayer);

		if (player.isDead()) { system("clear"); window.close(); }

		for (int i = 0; i < (int)enemies.size(); i++) {
			for (int j = 0; j < (int)enemies[i].size(); j++) {
				if (enemies[i][j].getPosition().y >= 480) {
					system("clear");
					window.close();
					return 0;
				}
			}
		}

		numberOfEnemies = 0;

		for (int i = 0; i < (int)enemies.size(); i++) numberOfEnemies += (int)enemies[i].size();

		if (numberOfEnemies == 0) {
			system("clear");
			window.close();
		}

		window.clear();

		for (int i = 0; i < (int)bulletsEnemies.size(); i++) {
			window.draw(bulletsEnemies[i]);
		}


		if (bulletActive) window.draw(bulletPlayer);

		for (int i = 0; i < (int)enemies.size(); i++) {
			for (int j = 0; j < (int)enemies[i].size(); j++) {
				window.draw(enemies[i][j]);
			}
		}

		for (int i = 0; i < 3; i++) window.draw(wall[i]);

		window.draw(player);


		window.display();
	}

	return 0;
} //end main

void updatePlayer(Player &player, Bullet &bulletPlayer) {

	player.update();

	if (player.shoot() && !bulletActive) {
		Bullet bullet(player.getPosition().x + 24, player.getPosition().y + 12, spritesheet, IntRect(13 * 8 + 16, 6 * 8 + 6, 8, 8), -10);
		bulletPlayer = bullet;
		bulletActive = true;
	}
}

void updateBulletPlayer(Bullet &bulletPlayer, vector<vector<Enemy>> &enemies) {

	if (bulletActive) {
		bulletPlayer.update();
		if (bulletPlayer.getPosition().y < -24) bulletActive = false;

		bulletRect = IntRect(bulletPlayer.getPosition().x, bulletPlayer.getPosition().y, 3, 8);
		for (int i = 0; i < (int)enemies.size(); i++) {
			for (int j = 0; j < (int)enemies[i].size(); j++) {
				enemyRect = IntRect(enemies[i][j].getPosition().x, enemies[i][j].getPosition().y, 24, 24);
				if (enemyRect.intersects(bulletRect)) {
					enemies[i].erase(enemies[i].begin() + j);
					bulletActive = false;

					break;
				}
			}
			if (!bulletActive) break;
		}
		if (!bulletActive) {
			for (int i = 0; i < (int)enemies.size(); i++) {
				for (int j = 0; j < (int)enemies[i].size(); j++) {
					enemies[i][j].decreaseResetTimer();

				}
			}
			resetTimer--;
		}
	}
}

void updateEnemies(vector<vector<Enemy>> &enemies) {

	maxX = 0;
	minX = 600;
	for (int i = 0; i < (int)enemies.size(); i++) {
		for (int j = 0; j < (int)enemies[i].size(); j++) {
			maxX = max(maxX, (int)enemies[i][j].getPosition().x + 24 * enemyDirection);
			minX = min(minX, (int)enemies[i][j].getPosition().x + 24 * enemyDirection);
		}
	}

	if (minX < 24 || maxX>576) {
		for (int i = 0; i < (int)enemies.size(); i++) {
			for (int j = 0; j < (int)enemies[i].size(); j++) {
				enemies[i][j].changeDirection();
			}
		}
		enemyDirection *= -1;
	}

	for (int i = 0; i < (int)enemies.size(); i++) {
		for (int j = 0; j < (int)enemies[i].size(); j++) {
			enemies[i][j].update();
		}
	}

	timer++;

	if (timer >= resetTimer && (int)enemies[0].size() > 0) {
		timer = 0;
		srand(time(NULL));
		int enem = rand() % (int)enemies[0].size();
		Bullet bullet = Bullet(enemies[0][enem].getPosition().x + 9, enemies[0][enem].getPosition().y + 24, spritesheet, IntRect(13 * 8 + 8, 8 * 2 + 2, 8, 8), 10);
		bulletsEnemies.push_back(bullet);
	}

}

void updateBulletsEnemies(Player& player) {

	for (int i = 0; i < (int)bulletsEnemies.size(); i++) {
		bulletsEnemies[i].update();
	}

	for (int i = 0; i < (int)bulletsEnemies.size(); i++) {
		if (bulletsEnemies[i].getPosition().y > 600) {
			bulletsEnemies.erase(bulletsEnemies.begin() + i);
		}
	}

	playerRect = IntRect(player.getPosition().x, player.getPosition().y + 9, 48, 15);
	for (int i = 0; i < (int)bulletsEnemies.size(); i++) {
		bulletRect = IntRect(bulletsEnemies[i].getPosition().x, bulletsEnemies[i].getPosition().y, 3, 24);
		if (playerRect.intersects(bulletRect)) {
			bulletsEnemies.erase(bulletsEnemies.begin() + i);
			player.reduceLives();
		}
	}

}

void updateWall(vector<Wall> &wall, Bullet &bulletPlayer) {
	if (bulletActive) {
		bulletRect = IntRect(bulletPlayer.getPosition().x, bulletPlayer.getPosition().y, 3, 8);
		for (int i = 0; i < 3; i++) {
			wall[i].getPosition(positionWall);
			for (int j = 0; j < (int)positionWall.size(); j++) {
				wallRect = IntRect(positionWall[j].second.x, positionWall[j].second.y, 24, 24);
				if (wallRect.intersects(bulletRect)) {
					wall[i].collision(positionWall[j].first, false);
					bulletActive = false;
				}
			}
			if (!bulletActive) break;
		}
	}

	bool elim = false;

	for (int h = 0; h < (int)bulletsEnemies.size(); h++) {
		bulletRect = IntRect(bulletsEnemies[h].getPosition().x, bulletsEnemies[h].getPosition().y, 3, 8);
		for (int i = 0; i < 3; i++) {
			wall[i].getPosition(positionWall);
			for (int j = 0; j < (int)positionWall.size(); j++) {
				wallRect = IntRect(positionWall[j].second.x, positionWall[j].second.y, 24, 24);
				if (wallRect.intersects(bulletRect)) {
					wall[i].collision(positionWall[j].first, true);
					bulletsEnemies.erase(bulletsEnemies.begin() + h);
					elim = true;
					break;
				}
			}
			if (elim) break;
		}
	}

	for (int i = 0; i < 3; i++) wall[i].update();
}
