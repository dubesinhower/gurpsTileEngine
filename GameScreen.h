#pragma once
#include "Screen.h"
#include <iostream>
#include "EnvironmentManager.h"

class GameScreen :
	public Screen
{
public:
	GameScreen(void);
	virtual int run(sf::RenderWindow& window);
	void update(float deltaTime);

private:
	sf::View view;
};