#include "Environment.h"

Environment::Environment(std::string mapFileName, std::string xmlFileName, sf::Texture& texture)
{
	if(!loadMap(mapFileName))
		std::cout << "could not load " << mapFileName << std::endl;
}

Environment::~Environment(void)
{
	
}

bool Environment::loadMap(std::string mapFileName)
{
	bool mapLoaded = false;
	map.clear();
	std::ifstream fin(mapFileName);
	if(fin.is_open())
	{
		std::string tempString;
		std::vector<std::string> tempStringTokenized;
		while(fin.good())
		{
			tempStringTokenized.clear();
			std::getline(fin, tempString);
			boost::split(tempStringTokenized, tempString, boost::is_any_of(" "));
			map.push_back(tempStringTokenized);
		}
		fin.close();
		mapLoaded = true;
	}

	std::cout << "map size " << map[0].size() << " by " << map.size() << std::endl;
	return mapLoaded;
}

void Environment::draw(sf::RenderWindow& window)
{

}