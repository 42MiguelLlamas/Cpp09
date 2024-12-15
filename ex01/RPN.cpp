#include "RPN.hpp"

RPN::RPN() 
{
}

RPN::RPN(const char *src)
{
	this->expression = src; 
}

RPN::RPN(const RPN &src)
{
	this->expression = src.expression;
	this->pila = src.pila;
}

RPN &RPN::operator=(const RPN &src)
{
	this->expression = src.expression;
	this->pila = src.pila;
	return *this;
}

RPN::~RPN()
{
	
}

int RPN::stringToInt(const std::string& str)
{
        std::istringstream iss(str);
        int num;
        iss >> num;
        if (iss.fail() || !iss.eof())
		{
            return 0;
        }
        return num;
    }

int RPN::solve()
{
	std::istringstream input(expression);
	std::string element;

	while (input >> element)
	{
		int num = stringToInt(element);
		if (num != 0)
		{
			if (element == "0")
				num = 0;
			if (num > 9)
				throw RPNException();
			pila.push(num);
		}
		else
		{
			if (element == "+" || element == "-" || element == "*" || element == "/")
			{
				if (pila.empty())
					throw RPNException();
				int a = pila.top();
				pila.pop();
				if (pila.empty())
					throw RPNException();
				int b = pila.top();
				pila.pop();
				if (element == "+")
					pila.push(a + b);
				if (element == "-")
					pila.push(b - a);
				if (element == "*")
					pila.push(a * b);
				if (element == "/")
				{
					if (a == 0)
						throw RPNException();
					pila.push(b / a);
				}
			}
			else
                throw RPNException();
		}
	}

	if (pila.size() != 1)
		throw RPNException();
	return pila.top();
}

const char *RPN::RPNException::what() const throw()
{
	return "Error.";
};