#pragma once
#include "Shape.h"
#include <SFML\Graphics.hpp>

class Rectangle:
	public Shape
{
public:
	Rectangle(sf::Vector2f topLeft, sf::Vector2f bottomRight, sf::Color borderColor)
	{
		setPosition(topLeft, bottomRight);
		graphic.setOutlineColor(borderColor);
		graphic.setFillColor(sf::Color::Transparent);
	};
	Rectangle(sf::Color borderColor)
	{
		graphic.setOutlineThickness(2.0f);
		graphic.setOutlineColor(borderColor);
		graphic.setFillColor(sf::Color::Transparent);
	}
	~Rectangle(void);
	void setBorderColor(sf::Color color) { graphic.setOutlineColor(color); };
	void setPosition(sf::Vector2f topLeft, sf::Vector2f bottomRight)
	{
		float width = bottomRight.x - topLeft.x;
		float height = bottomRight.y - topLeft.y;
		graphic.setPosition(topLeft.x, topLeft.y);
		graphic.setSize(sf::Vector2f(width, height));
	};
	void offsetPosition(sf::Vector2f offset) { graphic.move(offset.x, offset.y); };
	sf::FloatRect getPosition() { return sf::FloatRect(graphic.getPosition(), graphic.getSize()); };
	float getArea()
	{
		sf::Vector2f tempVector = graphic.getSize();
		return tempVector.x * tempVector.y;
	}
	void draw(sf::RenderWindow& window) { window.draw(graphic); };

private:
	sf::RectangleShape graphic;
};