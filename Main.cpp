#include <iostream>
#include <SFML\Graphics.hpp>
#include <boost\ptr_container\ptr_vector.hpp>
#include "Screens.h"

// starting point of the program
int main() 
{
	//create stack of screen objects
	boost::ptr_vector<Screen> screens;
	int currentScreen = 1;

	//create game window
	sf::RenderWindow window(sf::VideoMode(1366, 768, 32), "gurpsTileEngine");

	//create new gameScreen
	screens.push_back(new GameScreen);
	screens.push_back(new EditorScreen);

	//engine started, loops until one of the screens returns -1
	//switch screens based on the return int from the current screen
	//each screen is passed the window to draw objects
	while (currentScreen >= 0)
	{
		currentScreen = screens[currentScreen].run(window);
	}

	return 0;
}