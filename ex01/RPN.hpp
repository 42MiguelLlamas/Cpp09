#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>

class RPN
{
	public:
		RPN();
		RPN(const std::string& expression);
		RPN(const RPN& other);
		~RPN();

		RPN& operator=(const RPN& other);
		int evaluate();

	private:
		std::string expression;
		bool isOperator(const std::string& token) const;
		int applyOperation(int a, int b, const std::string& op) const;
};

#endif
