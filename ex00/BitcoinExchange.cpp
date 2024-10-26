#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
	std::cout << "Default constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string str) :  fileName(str)
{
	std::ifstream file = checkFile(fileName);
	this->dataBase = createDB(file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	this->fileName = src.fileName;
	this->dataBase = src.dataBase;

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{

}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor called." << std::endl;
}

std::ifstream BitcoinExchange::checkFile(std::string str)
{
	std::ifstream aux(str);
	if (!aux.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

}