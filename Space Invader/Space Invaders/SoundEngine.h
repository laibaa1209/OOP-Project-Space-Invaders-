#pragma once
#include <SFML/Audio.hpp>
using namespace sf;

class SoundEngine {
private:
	SoundBuffer m_invaderbuffer;
	SoundBuffer m_playerbuffer;
	SoundBuffer m_bulletbuffer;
	sf::Sound invader;
	Sound player;
	Sound bullet;

public:
	void playInvaderExplode() {
		m_invaderbuffer.loadFromFile("sound/invaderexplode.ogg");
		invader.play();
	}

	void playPlayerExplode() {
		m_playerbuffer.loadFromFile("sound/playerexplode.ogg");
		player.play();
	}

	void playBullet() {
		m_bulletbuffer.loadFromFile("sound/shoot.ogg");
		bullet.play();
	}


};