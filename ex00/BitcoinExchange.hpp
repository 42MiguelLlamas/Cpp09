#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>


class BitcoinExchange
{
	private:
		std::string fileName;
		std::map<std::string, float> dataBase;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string str);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		std::ifstream checkFile(std::string str);
		std::map<std::string, float> createDB(std::ifstream file);



};


#endif