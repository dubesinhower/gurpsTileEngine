#pragma once
#include <SFML\Graphics.hpp>

class Shape
{
public:
	virtual float getArea() { return NULL; };
	virtual void draw(sf::RenderWindow& window) {};
};