#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:

		std::string name;
		std::string effects;
		
	public:
		ASpell();
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell(){};
		std::string const &getName() const;
		std::string const &getEffects() const;

		void launch(ATarget const &src) const;
		virtual ASpell *clone() const = 0;
};



#endif