#pragma once
#include "SFML\Graphics.hpp"
#include <string>

class Text
{
public:
	Text(sf::Font& font);
	~Text(void);

	void setString(std::string string);
	void setAnchor(sf::Vector2f anchorPosition);
	void setJustification(int direction); //1-9
	void draw(sf::RenderWindow& window);

private:
	sf::Vector2f anchor;
	int justification;
	sf::Text text;
	void justifyText();
};