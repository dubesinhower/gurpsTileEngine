#include "Environment.h"

Environment::Environment(SpriteManager& spriteManager, std::string mapFileName, std::string xmlFileName)
{
	std::vector<std::vector<std::string> > map = loadMap(mapFileName);
	boost::property_tree::ptree pt = loadXml(xmlFileName);

	name = pt.get<std::string>("environment.name");
	std::cout << name << std::endl;
	int textureIndex = pt.get<int>("environment.textureIndex");
	std::cout << textureIndex << std::endl;
	int tileSize = pt.get<int>("environment.tileSize");
	std::cout << tileSize << std::endl;
	TileTypeManager ttm;
	for(boost::property_tree::ptree::value_type& v : pt.get_child("environment.tileTypes"))
		if(v.first == "type")
		{
			sf::Vector2i tempTexturePosition(v.second.get<int>("texturePosition.x"), v.second.get<int>("texturePosition.y"));
			ttm.addTileType(v.second.get<std::string>("name"), v.second.get<std::string>("mapIndicator"), tempTexturePosition, v.second.get<std::string>("logic"));
		}
	for(unsigned int i = 0; i < map.size(); i++)
	{
		tiles.push_back(new boost::ptr_vector<Tile>);
		for(unsigned int j = 0; j < map[0].size(); j++)
		{
			sf::Vector2f screenPosition = sf::Vector2f(float(j * tileSize), float(i * tileSize));
			//std::cout << ttm.getTexturePosition(map[i][j]).x << "," << ttm.getTexturePosition(map[i][j]).y << std::endl;
			tiles[i].push_back(new Tile(spriteManager.getSprite(textureIndex, tileSize, ttm.getTexturePosition(map[i][j])), screenPosition));
		}
		std::cout << std::endl;
	}
}

Environment::~Environment(void)
{
	
}

void Environment::draw(sf::RenderWindow& window)
{
	for(boost::ptr_vector<Tile> row : tiles)
		for(Tile tile : row)
		{
			tile.draw(window);
		}
}