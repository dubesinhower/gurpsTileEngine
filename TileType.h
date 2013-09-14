#pragma once
#include <string>
#include "SFML\System.hpp"

class TileType
{
public:
	TileType(std::string name, std::string mapIndicator, sf::Vector2i texturePosition, std::string logic);
	~TileType(void);

	std::string getName() { return name; };
	std::string getMapIndicator() { return mapIndicator; };
	sf::Vector2i getTexturePosition() { return texturePosition; };
	std::string getLogic() { return logic; };

private:
	std::string name;
	std::string mapIndicator;
	sf::Vector2i texturePosition;
	std::string logic;
};