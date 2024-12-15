#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <exception>
#include <cstdlib>
class BitcoinExchange
{
	private:
		std::map<std::string, float> dataBase;
		std::map<std::string, float> input;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void createDB(const std::string &str);
		void createInput(const std::string &str);
		void processInput(std::string str);
		void calculateExchange();
		class BitcoinException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};


};


#endif