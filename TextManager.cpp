#include "TextManager.h"

TextManager::TextManager(sf::FloatRect boundry)
{
	this->boundry = boundry;
	margin = 0;
}

TextManager::~TextManager(void)
{

}

void TextManager::setMargin(float margin)
{
	this->margin = margin;
}

sf::FloatRect TextManager::getInnerBoundry()
{
	float left = boundry.left + margin;
	float top = boundry.top + margin;
	float width = boundry.width - (2 * margin);
	float height = boundry.height - (2 * margin);
	return sf::FloatRect(left, top, width, height);
}