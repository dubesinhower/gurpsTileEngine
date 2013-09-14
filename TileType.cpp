#include "TileType.h"

TileType::TileType(std::string name, std::string mapIndicator, sf::Vector2i texturePosition, std::string logic)
{
	this->name = name;
	this->mapIndicator = mapIndicator;
	this->texturePosition = texturePosition;
	this->logic = logic;
}

TileType::~TileType(void)
{

}