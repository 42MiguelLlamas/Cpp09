#include "ATarget.hpp"

ATarget::ATarget(std::string const &type)
{
	this->type = type;
};

std::string const &ATarget::getType() const
{
	return this->type;
}


void ATarget::getHitBySpell(ASpell const &src) const
{
	std::cout << this->type << " has been " << src.getEffects() << "!\n";
};