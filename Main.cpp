#include <iostream>
#include <SFML\Graphics.hpp>
#include <vector>
#include "Screens.h"

// starting point of the program
int main() 
{
	//create stack of screen objects
	std::vector<Screen*> screens;
	int currentScreen = 0;

	//create game window
	sf::RenderWindow window(sf::VideoMode(1680, 1050, 32), "gurpsTileEngine");

	//create new gameScreen
	screens.push_back(new GameScreen);

	//engine started, loops until one of the screens returns -1
	//switch screens based on the return int from the current screen
	//each screen is passed the window to draw objects
	while (currentScreen >= 0)
	{
		currentScreen = screens[currentScreen]->run(window);
	}

	return 0;
}