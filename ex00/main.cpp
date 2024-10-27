#include "BitcoinExchange.hpp"
#include <iomanip>


void processInput(const std::string& inputFile, const BitcoinExchange& exchange)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
	{
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
	{
        std::istringstream stream(line);
        std::string date;
		std::string valueStr;
        double value;
        if (std::getline(stream, date, '|') && std::getline(stream >> std::ws, valueStr))
		{
            date.erase(date.find_last_not_of(" \n\r\t")+1);
            if (!exchange.isValidDate(date))
			{
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (!exchange.isValidValue(valueStr, value))
			{
                std::cerr << "Error: not a positive number or too large." << std::endl;
                continue;
            }
            double price = exchange.getClosestPrice(date);
            std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << value * price << std::endl;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: ./btc <input file>" << std::endl;
        return 1;
    }
    BitcoinExchange exchange("data.csv");
    if (!exchange.loadDatabase())
	{
        std::cerr << "Error: database is empty or invalid." << std::endl;
        return 1;
    }
    processInput(argv[1], exchange);
    return 0;
}

