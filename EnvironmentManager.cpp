#include "EnvironmentManager.h"

EnvironmentManager::EnvironmentManager(SpriteManager& spriteManager)
{
	loadEnvironments(spriteManager);
}

EnvironmentManager::~EnvironmentManager(void)
{

}

void EnvironmentManager::update(float deltaTime)
{

}

void EnvironmentManager::draw(sf::RenderWindow& window)
{
	environments[0][0].draw(window);
}

void EnvironmentManager::loadEnvironments(SpriteManager& spriteManager)
{
	addEnvironmentToVector(new Environment(spriteManager, "Data/overworldDevEnvTest.map", "Data/overworldDevEnv.xml"));
}

void EnvironmentManager::addEnvironmentToVector(Environment* environment)
{
	environments.push_back(new boost::ptr_vector<Environment>);
	environments[0].push_back(environment);
}

bool EnvironmentManager::addEnvironmentToVector(Environment* environment, int index)
{
	bool environmentAdded = false;
	if(index < environments.size() && index >= 0)
	{
		environments[index].push_back(environment);
		environmentAdded = true;
	}
	else
	{
		std::cout << "environment not added " << std::endl;
	}
	return environmentAdded;
}