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
		std::map<std::string, double> btcPrices;
		std::string databaseFile;
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& databaseFile);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		bool loadDatabase();
		double getClosestPrice(const std::string& date) const;
		bool isValidDate(const std::string& date) const;
		bool isValidValue(const std::string& valueStr, double& value) const;
};

#endif