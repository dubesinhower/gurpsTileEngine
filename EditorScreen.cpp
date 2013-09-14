#include "EditorScreen.h"

EditorScreen::EditorScreen(void)
{

}

EditorScreen::~EditorScreen(void)
{

}

int EditorScreen::run(sf::RenderWindow &window)
{
	float viewSpeed = 500.0f;

	//initialize deltaTime variable and clock
	float deltaTime = 0.0f;
	sf::Clock clock;

	sf::View editorView;
	sf::View guiView;

	sf::Vector2f windowSize = (sf::Vector2f)window.getSize();
	editorView.reset(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
	editorView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	guiView.reset(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
	guiView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	SpriteManager spriteManager;
	FontManager fontManager;
	EnvironmentManager environmentManager(spriteManager);

	Text text(fontManager.getFont(0));

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
				case sf::Keyboard::F1:
					editorView.reset(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
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
			editorView.move(sf::Vector2f(0.0f, -viewSpeed*deltaTime));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			editorView.move(sf::Vector2f(0.0f, viewSpeed*deltaTime));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			editorView.move(sf::Vector2f(-viewSpeed*deltaTime, 0.0f));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			editorView.move(sf::Vector2f(viewSpeed*deltaTime, 0.0f));
		}

		sf::Vector2f mapOffset = getViewTopLeftPosition(editorView);
		std::string mapOffsetString = std::to_string((int)mapOffset.x) + "," + std::to_string((int)mapOffset.y);
		text.setString(mapOffsetString);

		window.clear();
		window.setView(editorView);
		environmentManager.draw(window);
		window.setView(guiView);
		text.draw(window);
		window.display();
	}

	return (-1);
}

sf::Vector2f EditorScreen::getViewTopLeftPosition(sf::View view)
{
	sf::Vector2f viewCenter = view.getCenter();
	sf::Vector2f viewSize = view.getSize();
	return sf::Vector2f(viewCenter.x - (viewSize.x * .5f), viewCenter.y - (viewSize.y * .5f));
}