#include "RPN.hpp"
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

RPN::RPN() : expression("")
{

}

RPN::RPN(const std::string& expr) : expression(expr)
{

}

RPN::RPN(const RPN& other) : expression(other.expression)
{

}

RPN::~RPN()
{
	
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
	    expression = other.expression;
    return *this;
}

bool RPN::isOperator(const std::string& token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}


int RPN::applyOperation(int a, int b, const std::string& op) const
{
    if (op == "+")
		return a + b;
    if (op == "-")
		return a - b;
    if (op == "*")
		return a * b;
    if (op == "/")
	{
        if (b == 0)
			throw std::runtime_error("Error: Division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: Invalid operator");
}

int RPN::evaluate()
{
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
	{
        if (std::isdigit(token[0]))
            stack.push(std::atoi(token.c_str()));
		else if (isOperator(token))
		{
            if (stack.size() < 2)
				throw std::runtime_error("Error: Invalid expression");
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result = applyOperation(a, b, token);
            stack.push(result);
        }
		else
            throw std::runtime_error("Error: Invalid token");
    }

    if (stack.size() != 1)
		throw std::runtime_error("Error: Invalid expression");
    return stack.top();
}
