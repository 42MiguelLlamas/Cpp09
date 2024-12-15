#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <exception>
#include <cstdlib>


class RPN
{
	private:
		std::string expression;
		std::stack <int> pila;

	public:
		RPN();
		~RPN();
		RPN(const char *src);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		int stringToInt(const std::string& str);
		int solve();
		class RPNException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};


#endif