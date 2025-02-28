#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"


class SpellBook
{
	private:
		std::map<std::string, ASpell*> arr;
		SpellBook(const SpellBook &src);
		SpellBook &operator=(const SpellBook &src);
		
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *src);
		void forgetSpell(std::string const &src);
		ASpell* createSpell(std::string const &src);
};


#endif