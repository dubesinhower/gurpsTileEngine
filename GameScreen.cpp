#include "GameScreen.h"

GameScreen::GameScreen(void)
{

}

int GameScreen::run(sf::RenderWindow &window)
{
	float viewSpeed = 1000.0f;

	//initialize deltaTime variable and clock
	float deltaTime = 0.0f;
	sf::Clock clock;

	sf::Vector2f windowSize = (sf::Vector2f)window.getSize();

	//set the camera to the center of the level
	//view.reset(sf::FloatRect(sf::Vector2f(level.getDimension()/2), windowSize));

	EnvironmentManager environmentManager;

	//screen loop starts
	bool running = true;
	sf::Event event;
	while(true == running)
	{
		deltaTime = clock.restart().asSeconds();
		//std::cout << deltaTime << std::endl;
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		//sfml event management loop
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				return (-1);
			}

			if(event.type == sf::Event::KeyPressed)
			{
				switch(event.key.code)
				{
				case sf::Keyboard::Escape:
					return (-1);
					break;
				default:
					break;
				}
			}
			if(event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				//std::cout << "mouse start: " << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << std::endl;
			}
			if(event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				//std::cout << "mouse end: " << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << std::endl;
			}
		}
		//event loop finished

		//view scrolling
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			view.move(sf::Vector2f(0.0f, -viewSpeed*deltaTime));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			view.move(sf::Vector2f(0.0f, viewSpeed*deltaTime));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			view.move(sf::Vector2f(-viewSpeed*deltaTime, 0.0f));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			view.move(sf::Vector2f(viewSpeed*deltaTime, 0.0f));
		}

		sf::Vector2f viewCenter = view.getCenter();
		sf::Vector2f viewSize = view.getSize();
		sf::Vector2f viewTopLeft(viewCenter.x - .5f * viewSize.x, viewCenter.y - .5f * viewSize.y);
		sf::Vector2f viewBottomRight(viewCenter.x + .5f * viewSize.x, viewCenter.y + .5f * viewSize.y);

		//update the player (not necessary yet)
		//player.update(deltaTime, level, mousePosition);

		//draw objects
		window.clear();
		window.setView(view);
		environmentManager.draw(window);
		window.display();
	}

	return (-1);
}