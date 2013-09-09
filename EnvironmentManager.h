#pragma once
#include "SFML\Graphics.hpp"
#include "Environment.h"

class EnvironmentManager
{
public:
	EnvironmentManager(void);
	~EnvironmentManager(void);

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

private:
	Environment test;
};