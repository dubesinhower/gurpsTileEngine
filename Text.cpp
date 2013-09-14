#include "Text.h"

Text::Text(sf::Font& font)
{
	text.setFont(font);
	setAnchor(sf::Vector2f(0,0));
	setJustification(1);
	justifyText();
}

Text::~Text(void)
{

}

void Text::setString(std::string string)
{
	text.setString(string);
}

void Text::setAnchor(sf::Vector2f anchorPosition)
{
	anchor = anchorPosition;
}

void Text::setJustification(int direction)
{
	justification = direction;
}

void Text::draw(sf::RenderWindow& window)
{
	justifyText();
	window.draw(text);
}

void Text::justifyText()
{
	switch(justification)
	{
	case 1:
		text.setPosition(anchor);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;

	}
}