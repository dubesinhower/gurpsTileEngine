#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <vector>
#include <iostream>

class TextureManager
{
public:
	TextureManager(void);
	~TextureManager(void);

	void addTexture(std::string textureFileName);
	sf::Texture& getTexture(int index);

private:
	std::vector<sf::Texture> textures;
};