#include "SpellBook.hpp"

SpellBook::SpellBook(){};

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		delete it->second;
	}
	arr.clear();
}

void SpellBook::learnSpell(ASpell *src)
{
	arr[src->getName()] = src->clone();
};


void SpellBook::forgetSpell(std::string const &src)
{
	std::map<std::string, ASpell *>::iterator it = arr.find(src);
	if (it != arr.end())
	{
		delete it->second;
		arr.erase(src);
	}
	
};

ASpell* SpellBook::createSpell(std::string const &src)
{
	std::map<std::string, ASpell*>::iterator it = arr.find(src);
	if (it != arr.end())
	{
		return it->second->clone();
	}
	return NULL;
};