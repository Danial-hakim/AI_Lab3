#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenSize.h"

class Player
{
public:
	void init();
	void update();
	void render(sf::RenderWindow& win);
	void updateDirection();
	void updateVelocity();

	void processGamesEvent();

	void increaseSpeed();
	void decreaseSpeed();
	void increaseRotation();
	void decreaseRotation();

	void checkBoundary();

	sf::Vector2f getPos();

private:

	float speed = 1;
	//sf::Vector2f velocity = { 1, 0 };

	sf::Sprite sprite;
	sf::Texture texture;

	float rotation = 0;

	const float MAX_SPEED{ 5.0f };

	float previousSpeed;

	float previousRotation;

	sf::Vector2f currentPosition;

	sf::Vector2f previousPosition;
};