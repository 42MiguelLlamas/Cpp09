#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <map>
#include "ATarget.hpp"


class TargetGenerator
{
	private:
		std::map<std::string, ATarget*> arr;
		TargetGenerator(const TargetGenerator &src);
		TargetGenerator &operator=(const TargetGenerator &src);
		
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *src);
		void forgetTargetType(std::string const &src);
		ATarget* createTarget(std::string const &src);
};

#endif