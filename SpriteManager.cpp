#include "SpriteManager.h"

SpriteManager::SpriteManager(void)
{
	addTexture("Images/overWorldDevEnv.png");
}

SpriteManager::~SpriteManager(void)
{

}

void SpriteManager::addTexture(std::string textureFileName)
{
	sf::Texture tempTexture;
	if(!tempTexture.loadFromFile(textureFileName))
		std::cout << "could not load " << textureFileName << std::endl;
	textures.push_back(tempTexture);
}

sf::Sprite* SpriteManager::getSprite(int textureIndex, int tilePixelSize, sf::Vector2i texturePosition)
{
	if(textureIndex < textures.size() && textureIndex >= 0)
	{
		sf::Vector2i textureCoordinates = texturePosition * tilePixelSize;
		sf::IntRect textureRect(textureCoordinates, sf::Vector2i(tilePixelSize, tilePixelSize));
		sf::Sprite* tempSprite = new sf::Sprite(textures[textureIndex],textureRect);
		return tempSprite;
	}
	return new sf::Sprite();
}