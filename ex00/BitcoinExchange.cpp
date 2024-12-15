#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	this->input = src.input;
	this->dataBase = src.dataBase;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	this->input = src.input;
	this->dataBase = src.dataBase;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	
}

void printMap(const std::map<std::string, float> &map)
{
    std::map<std::string, float>::const_iterator it;
    for (it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}

bool isValidDate(const std::string &date)
{
	if (date.size() != 10)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	if (date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return false;
		}
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	return true;
}

bool isValidValue(const float& value)
{
    if (value <= 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    
    return true;
}

void BitcoinExchange::createDB(const std::string &str)
{
	std::ifstream aux(str.c_str());
	if (!aux.is_open())
		throw BitcoinException();
	std::string line;
    bool isFirstLine = true;
	while (std::getline(aux, line))
	{
		if (isFirstLine)
		{ 
			isFirstLine = false; 
			continue; 
		}

		std::istringstream lineStream(line);
		std::string date, value;

		if (std::getline(lineStream, date, ',') && std::getline(lineStream, value))
		{
			date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
			value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
			dataBase[date] = static_cast<float>(std::atof(value.c_str()));
		}
	}
    aux.close();
}

void BitcoinExchange::createInput(const std::string &str)
{
	std::ifstream aux(str.c_str());
	if (!aux.is_open())
		throw BitcoinException();
	std::string line;
    bool isFirstLine = true;
	while (std::getline(aux, line))
	{
		if (isFirstLine)
		{ 
			isFirstLine = false; 
			continue; 
		}

		std::istringstream lineStream(line);
		std::string date, value;

		if (std::getline(lineStream, date, '|') && std::getline(lineStream, value))
		{
			date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
			value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
			float valuef = static_cast<float>(std::atof(value.c_str()));
			std::map<std::string, float>::iterator itDB = this->dataBase.lower_bound(date);
			const std::string &dbDate = itDB->first;
			if (itDB == this->dataBase.end() || dbDate != date)
			{
				if (itDB != this->dataBase.begin())
					--itDB;
				else
				{
					std::cerr << "Warning: No suitable date found in database for " << date << "." << std::endl;
					continue;
				}
			}
			float dbValue = itDB->second;
			float result = valuef * dbValue;
			//std::cout << "Value:" << valuef << " - Value DB: " << dbValue << "\nDate: " << date << "- DB date:" << dbDate<< std::endl;
			if (!isValidDate(date) || !isValidDate(dbDate))
				continue;
			if (!isValidValue(valuef) || !isValidValue(dbValue))
				continue;
			std::cout << date << " => " << valuef << " = " << result << std::endl;
		}
		else
		{
			std::getline(lineStream, date);
			std::cout << "Error: bad input => " << date << std::endl;
		}
	}
    aux.close();
}

void BitcoinExchange::processInput(std::string str)
{
	this->createDB("data.csv");
	this->createInput(str);
	printMap(this->input);
	//this->calculateExchange();
}

const char *BitcoinExchange::BitcoinException::what() const throw()
{
	return "Error.";
};