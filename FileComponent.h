#pragma once
#include <vector>
#include <string>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\xml_parser.hpp>
#include <boost\algorithm\string.hpp>
#include <fstream>
#include <iostream>

class FileComponent
{
public:
	FileComponent(void);
	~FileComponent(void);

	std::vector<std::vector<std::string> > loadMap(std::string mapFileName);
	boost::property_tree::ptree loadXml(std::string xmlFileName);
};

