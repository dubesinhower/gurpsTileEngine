#pragma once
#include "SFML\Graphics.hpp"
#include <boost\ptr_container\ptr_vector.hpp>
#include "Environment.h"
#include "SpriteManager.h"

class EnvironmentManager
{
public:
	EnvironmentManager(SpriteManager& spriteManager);
	~EnvironmentManager(void);

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

private:
	void loadEnvironments(SpriteManager& spriteManager);
	void addEnvironmentToVector(Environment* environment);
	bool addEnvironmentToVector(Environment* environment, int index);

	boost::ptr_vector<boost::ptr_vector <Environment>> environments;
};