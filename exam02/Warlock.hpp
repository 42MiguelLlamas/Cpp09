#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:

		std::string name;
		std::string title;

		std::map<std::string, ASpell *> arr;
		SpellBook book;
		Warlock();
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;

		void setTitle(std::string const &title);
		void introduce() const;

		void learnSpell(ASpell *src);
		void forgetSpell(std::string const &src);
		void launchSpell(std::string const &src, ATarget const &target);
};



#endif