#pragma once
#include <vector>
#include <SFML\System.hpp>
#include <boost\ptr_container\ptr_vector.hpp>
#include "TileType.h"

class TileTypeManager
{
public:
	TileTypeManager(void);
	~TileTypeManager(void);

	void addTileType(std::string name, std::string mapIndicator, sf::Vector2i texturePosition, std::string logic);
	sf::Vector2i getTexturePosition(std::string mapIndicator);
	std::string getLogic(std::string mapIndicator);

private:
	boost::ptr_vector<TileType> tileTypes;
};