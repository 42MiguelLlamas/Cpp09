#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange MyData;
			MyData.processInput(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
	}
}