#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : databaseFile("")
{
}

BitcoinExchange::BitcoinExchange(const std::string& dbFile):databaseFile(dbFile)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	btcPrices = other.btcPrices;
	databaseFile = other.databaseFile;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other) {
        btcPrices = other.btcPrices;
        databaseFile = other.databaseFile;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::loadDatabase()
{
    std::ifstream file(databaseFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string date, priceStr;
        if (std::getline(stream, date, ',') && std::getline(stream, priceStr)) {
            if (isValidDate(date)) {
                double price;
                std::istringstream(priceStr) >> price;
                btcPrices[date] = price;
            }
        }
    }
    return true;
}

double BitcoinExchange::getClosestPrice(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = btcPrices.lower_bound(date);
    if (it == btcPrices.end() || (it != btcPrices.begin() && it->first != date)) {
        --it;
    }
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    int year, month, day;
    char dash1, dash2;
    std::istringstream dateStream(date);
    dateStream >> year >> dash1 >> month >> dash2 >> day;
    if (dateStream.fail() || dash1 != '-' || dash2 != '-') return false;
    return (year >= 2000 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const
{
    std::istringstream iss(valueStr);
    iss >> value;
    return (!iss.fail() && value >= 0 && value <= 1000);
}
