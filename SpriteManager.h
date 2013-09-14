#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <vector>
#include <iostream>

class SpriteManager
{
public:
	SpriteManager(void);
	~SpriteManager(void);

	sf::Sprite* getSprite(int textureIndex, int tilePixelSize, sf::Vector2i texturePosition);

private:
	void addTexture(std::string textureFileName);
	std::vector<sf::Texture> textures;
};