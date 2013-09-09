#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>


class Environment
{
public:
	Environment(std::string mapFileName, std::string xmlFileName, sf::Texture& texture);
	~Environment(void);

	void draw(sf::RenderWindow& window);

private:
	std::vector<std::vector<std::string> > map;
	std::vector<sf::Sprite> sprites;
	bool loadMap(std::string mapFileName);
};