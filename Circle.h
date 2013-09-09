#pragma once
#include "Shape.h"
#include <SFML\Graphics.hpp>
#include <boost\math\constants\constants.hpp>
#include <math.h>

class Circle :
	public Shape
{
public:
	Circle(sf::Vector2f position, float radius)
	{
		graphic.setPosition(position);
		graphic.setRadius(radius);
		graphic.setOrigin(sf::Vector2f(radius, radius));
	};
	~Circle(void);
	void setFillColor(sf::Color color) { graphic.setFillColor(color); };
	void setPosition(sf::Vector2f position) { graphic.setPosition(position); };
	void setPositionX(float xPosition) { graphic.setPosition(xPosition, graphic.getPosition().y); };
	void setPositionY(float yPosition) { graphic.setPosition(graphic.getPosition().x, yPosition); };
	void setRadius(float radius)
	{
		graphic.setRadius(radius);
		graphic.setOrigin(sf::Vector2f(radius, radius));
	};
	void offsetPosition(sf::Vector2f positionOffset) { graphic.setPosition(graphic.getPosition() + positionOffset); };
	sf::Vector2f getPosition() { return graphic.getPosition(); };
	float getRadius() { return graphic.getRadius(); };
	float getArea() 
	{
		float pi = boost::math::constants::pi<float>();
		std::cout << pi * pow(getRadius(), 2) << std::endl;
		return (pi * pow(getRadius(), 2)); 
	};
	void draw(sf::RenderWindow& window)  { window.draw(graphic); };

private:
	sf::CircleShape graphic;
};

