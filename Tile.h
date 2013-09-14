#pragma once
#include "SFML\Graphics.hpp"
#include <boost\ptr_container\ptr_vector.hpp>

class Tile
{
public:
	Tile(sf::Sprite* sprite, sf::Vector2f screenPosition);
	~Tile(void);

	void draw(sf::RenderWindow& window);
private:
	boost::ptr_vector<sf::Sprite> spriteContainer;
};