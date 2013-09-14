#pragma once
#include "SFML\Graphics.hpp"
#include <boost\ptr_container\ptr_vector.hpp>
class TextManager
{
public:
	TextManager(sf::FloatRect boundry);
	~TextManager(void);

	void setMargin(float margin);
private:

	sf::FloatRect getBoundry() { return boundry; }
	sf::FloatRect getInnerBoundry();
	sf::FloatRect boundry;
	float margin;
};