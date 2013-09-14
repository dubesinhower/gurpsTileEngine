#pragma once
#include "Screen.h"
#include <iostream>
#include "SpriteManager.h"
#include "EnvironmentManager.h"
#include "FontManager.h"
#include "Text.h"

class EditorScreen :
	public Screen
{
public:
	EditorScreen(void);
	~EditorScreen(void);

	int run(sf::RenderWindow& window);

private:
	sf::Vector2f getViewTopLeftPosition(sf::View view);
};