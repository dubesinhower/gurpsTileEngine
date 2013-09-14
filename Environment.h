#pragma once
#include "SFML\Graphics.hpp"
#include <boost\property_tree\xml_parser.hpp>
#include <boost\property_tree\ptree.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "SpriteManager.h"
#include "Tile.h"
#include "TileTypeManager.h"
#include "FileComponent.h"

class Environment : FileComponent
{
public:
	Environment(SpriteManager& spriteManager, std::string mapFileName, std::string xmlFileName);
	~Environment(void);

	void draw(sf::RenderWindow& window);

private:
	std::string name;
	boost::ptr_vector<boost::ptr_vector<Tile> > tiles;
};