#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->name <<": My job here is done!\n";
	for (std::map<std::string, ASpell*>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		delete it->second;
	}
	arr.clear();
}
std::string const &Warlock::getName() const
{
	return this->name;
}

std::string const &Warlock::getTitle() const
{
	return this->title;
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << this->name<<": I am " << this->name <<", "<< this->title << "!\n";
}

void Warlock::learnSpell(ASpell const *src)
{
	if (src)
		arr[src->getName()] = src->clone();
};

void Warlock::forgetSpell(std::string const &src)
{
	std::map<std::string, ASpell *>::iterator it = arr.find(src);
	if (it != arr.end())
	{
		delete it->second;
		arr.erase(it);
	}
};

void Warlock::launchSpell(std::string const &src, ATarget const &target)
{
	if (arr.find(src) != arr.end())
	{
		arr[src]->launch(target);
	}
};