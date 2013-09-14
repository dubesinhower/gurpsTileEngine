#include "TileTypeManager.h"

TileTypeManager::TileTypeManager(void)
{

}

TileTypeManager::~TileTypeManager(void)
{

}

void TileTypeManager::addTileType(std::string name, std::string mapIndicator, sf::Vector2i texturePosition, std::string logic)
{
	tileTypes.push_back(new TileType(name, mapIndicator, texturePosition, logic));
}

sf::Vector2i TileTypeManager::getTexturePosition(std::string mapIndicator)
{
	for(TileType tt : tileTypes)
	{
		if(tt.getMapIndicator() == mapIndicator)
			return tt.getTexturePosition();
	}
	return sf::Vector2i(0, 0);
}

std::string TileTypeManager::getLogic(std::string mapIndicator)
{
	for(TileType tt : tileTypes)
	{
		if(tt.getMapIndicator() == mapIndicator)
			return tt.getLogic();
	}
	return "none";
}