#include "EnvironmentManager.h"

EnvironmentManager::EnvironmentManager(void) : test("Data/test.map")
{
	
}

EnvironmentManager::~EnvironmentManager(void)
{

}

void EnvironmentManager::update(float deltaTime)
{

}

void EnvironmentManager::draw(sf::RenderWindow& window)
{
	test.draw(window);
}