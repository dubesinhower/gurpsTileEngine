#include "Tile.h"

Tile::Tile(sf::Sprite* sprite, sf::Vector2f screenPosition)
{
	this->spriteContainer.push_back(sprite);
	spriteContainer[0].setPosition(screenPosition);
}

Tile::~Tile(void)
{
	
}

void Tile::draw(sf::RenderWindow& window)
{
	window.draw(spriteContainer[0]);
}