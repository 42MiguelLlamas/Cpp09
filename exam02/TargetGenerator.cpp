#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string, ATarget*>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		delete it->second;
	}
	arr.clear();
}

void TargetGenerator::learnTargetType(ATarget *src)
{
	if (src)
	{
		if (arr.find(src->getType()) != arr.end())
			delete arr[src->getType()];
		arr[src->getType()] = src->clone();
	}
};


void TargetGenerator::forgetTargetType(std::string const &src)
{
	std::map<std::string, ATarget *>::iterator it = arr.find(src);
	if (it != arr.end())
	{
		delete it->second;
		arr.erase(it);
	}
	
};

ATarget* TargetGenerator::createTarget(std::string const &src)
{
	std::map<std::string, ATarget*>::iterator it = arr.find(src);
	if (it != arr.end())
	{
		return it->second->clone();
	}
	return NULL;
};