#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include <iostream>

class FontManager
{
public:
	FontManager(void);
	~FontManager(void);

	sf::Font& getFont(int fontIndex);

private:
	std::vector<sf::Font> fonts;
	void addFont(std::string fontFileName);
};

