#include "FontManager.h"

FontManager::FontManager(void)
{
	addFont("Fonts/Telespania.ttf");
}

FontManager::~FontManager(void)
{

}

sf::Font& FontManager::getFont(int fontIndex)
{
	return fonts[fontIndex];
}

void FontManager::addFont(std::string fontFileName)
{
	sf::Font tempFont;
	if(!tempFont.loadFromFile(fontFileName))
		std::cout << "could not load " << fontFileName << std::endl;
	fonts.push_back(tempFont);
}