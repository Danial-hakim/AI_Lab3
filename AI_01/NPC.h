#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ScreenSize.h>
#include "Maths.h"

struct Kinematics
{
	sf::Vector2f position;
	float orientation;
	sf::Vector2f velocity;
	float rotation;
};

struct SteeringOutput
{
	sf::Vector2f linear;
	float angular;
};

class NPC
{
public:

	void init();
	void update(float dt, sf::Vector2f playerPos, int enemyType);
	void render(sf::RenderWindow& win);

	void checkBoundary();

	void kinematicsUpdate(float dt);

	void getSteering(int enemyType);

	void updateMovement();

	void updateOrientation();

	void resetToMiddle();

protected:

	sf::Sprite sprite;
	sf::Texture texture;

	int xBoundary = ScreenSize::s_width;
	int yBoundary = ScreenSize::s_height;

	sf::Vector2f m_playerPos;

	sf::Vector2f currentPosition;

	float rotation;

	float maxSpeed = 100.0f;

	Kinematics kinematics;
	SteeringOutput steering;

	float maxAcceleration = 95.0f;

	float reachRad = 10.0f;
	float slowRad = 200.0f;

	float targetSpeed;
};