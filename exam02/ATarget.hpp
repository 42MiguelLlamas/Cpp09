#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string type;
		
	public:
		ATarget();
		ATarget(std::string const &type);
		virtual ~ATarget(){};

		std::string const &getType() const;

		void getHitBySpell(const ASpell &src) const;

		virtual ATarget *clone() const = 0;
};



#endif