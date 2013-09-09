#include "TextureManager.h"

TextureManager::TextureManager(void)
{

}

TextureManager::~TextureManager(void)
{

}

void TextureManager::addTexture(std::string textureFileName)
{
	sf::Texture tempTexture;
	if(!tempTexture.loadFromFile(textureFileName))
		std::cout << "could not load " << textureFileName << std::endl;
	textures.push_back(tempTexture);
}

sf::Texture& TextureManager::getTexture(int index)
{
	return textures[index];
}