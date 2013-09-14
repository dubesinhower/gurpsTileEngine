#include "FileComponent.h"

FileComponent::FileComponent(void)
{

}

FileComponent::~FileComponent(void)
{

}

std::vector<std::vector<std::string> > FileComponent::loadMap(std::string mapFileName)
{
	std::vector<std::vector<std::string> > map;
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
		std::cout << "map loaded: " << map.size() << " by " << map[0].size() << std::endl;
	}
	else 
	{
		std::cout << "could not load " << mapFileName << std::endl;
	}
	return map;
}

boost::property_tree::ptree FileComponent::loadXml(std::string xmlFileName)
{
	boost::property_tree::ptree pt;
	std::ifstream fin(xmlFileName);
	if(fin.is_open())
	{
		boost::property_tree::read_xml(fin, pt);
		std::cout << "xml loaded: " << pt.size() << " items" << std::endl;
	}
	else
		std::cout << "could not load " << xmlFileName << std::endl;
	pt.size();
	return pt;
}