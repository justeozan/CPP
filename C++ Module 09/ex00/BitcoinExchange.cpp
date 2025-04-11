#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &src) {
	this->_data = src._data;
	return (*this);
}
BitcoinExchange::~BitcoinExchange() {}

//verif function
std::tm    BitcoinExchange::parseDate(std::string date) {
	std::tm tm_buf;

	memset(&tm_buf, 0, sizeof(std::tm));
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm_buf))
		throw std::runtime_error("Error: bad input => " + date);
	return (tm_buf);
}

float    BitcoinExchange::parseRate(std::string number) {
	std::istringstream	iss(number);
	float				rate;

	iss >> rate;
	if (rate < 0)
		throw std::runtime_error("Error: not a positive number");
	if (rate > 10000000)
		throw std::runtime_error("Error: too large a number");
	return (rate);
}

void	BitcoinExchange::registerData(const char* filename) {
	std::string		line;
	std::ifstream	filestream;

	filestream.open(filename);
	if (!filestream)
		throw std::runtime_error("Error: " + std::string(filename) + ": file can't be opened");

	std::getline(filestream, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: " + std::string(filename) + ": invalid header");
	while (std::getline(filestream, line)) {
		std::istringstream	iss(line);	//this is a stream of the line, the stream is separated by ','
		std::string			date, rate;
		std::getline(iss, date, ',');
		std::getline(iss, rate, ',');
		_data[parseDate(date)] = parseRate(rate);
	}
	filestream.close();
}

//main function
void	BitcoinExchange::run(const char* transFile, const char* filename) {
	if (!transFile || !filename)
		throw std::runtime_error("Error: invalid arguments");
	registerData(filename);
	// printData();
	displayTransactions(transFile);
	(void)transFile;
}

//display function
void	BitcoinExchange::displayValues(std::string date, std::string amount) {
	std::tm	tmDate = parseDate(date);
	std::map<std::tm, float, tmCompare>::iterator it = _data.lower_bound(tmDate);

	// Case where the date is strictly greater than all dates in the map
	if (it == _data.begin()) {
		if (!(it->first.tm_year == tmDate.tm_year && it->first.tm_mon  == tmDate.tm_mon  && it->first.tm_mday == tmDate.tm_mday))
			throw std::runtime_error("Error: no available previous date for the given date.");
	}
	// If the exact date is not found, we go back to get the previous date
	else if (!(it != _data.end() && it->first.tm_year == tmDate.tm_year && it->first.tm_mon  == tmDate.tm_mon && it->first.tm_mday == tmDate.tm_mday))
		--it;		// we take the previous date
	float rate = it->second;
	// std::cout << DISCRET << "parsing date :" << date << ". value found in data: " << rate << RESET << std::endl;
	rate = parseRate(amount) * rate;
	if (rate > 1000)
		throw std::runtime_error("Error: " + amount + ": too large a number");
	std::cout << date << " => " << amount << " = " << rate << std::endl;
}

void	BitcoinExchange::displayTransactions(char const* filename) {
	std::string		line;
	std::ifstream	filestream;

	filestream.open(filename);
	if (!filestream)
		throw std::runtime_error("Error: " + std::string(filename) + ": file can't be opened");

	std::getline(filestream, line);
	if (line != "date | value")
		throw std::runtime_error("Error: " + std::string(filename) + ": invalid header");
	while (std::getline(filestream, line)) {
		std::istringstream	iss(line);
		std::string			date, amount;
		std::getline(iss, date, '|');
		std::getline(iss, amount, '|');
		try {
			displayValues(date.erase(date.find_last_not_of(" \t") + 1), amount.erase(0, amount.find_first_not_of(" \t")));
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
}

void	BitcoinExchange::printData() const {
	std::map<std::tm, float, tmCompare>::const_iterator it = _data.begin();
	std::cout << "=====[ MY DATA ]=====" << std::endl;
	for (int i = 0; i < 3; ++i) {
		char buffer[20];
		strftime(buffer, sizeof(buffer), "%Y-%m-%d", &it->first);
        std::cout << buffer << ", " << it->second << std::endl;
        ++it;
	}
	std::cout << "======= ... ========" << std::endl;
	it = _data.end();
	--it;
	--it;
	--it;
	for (int i = 0; i < 3; ++i) {
		char buffer[20];
		strftime(buffer, sizeof(buffer), "%Y-%m-%d", &it->first);
        std::cout << buffer << ", " << it->second << std::endl;
		++it;
	}
	std::cout << "=====================" << std::endl;
}