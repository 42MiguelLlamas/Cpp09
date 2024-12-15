#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			RPN MyExpression(argv[1]);
			int result = MyExpression.solve();
			std::cout << result << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	else
	{
		std::cout << "Error: bad number of arguments" << std::endl;
	}
}