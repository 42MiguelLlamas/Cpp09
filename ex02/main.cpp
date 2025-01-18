#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		try
		{
			PmergeMe MyExpression(argv, argc);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	else
	{
		std::cout << "Error: Bad number of arguments." << std::endl;
	}
}