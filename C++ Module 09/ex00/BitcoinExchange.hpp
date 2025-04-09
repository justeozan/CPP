
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>

class BitcoinExchange {
	private:
		//tab1
		//tab2
		map<std::tm, float, comparator> 
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		//file function
		std::ifstream&    registerData(std::ifstream& filestream, const char* filename);
		std::ifstream&    registerTransactions(std::ifstream& filestream, const char* filename);

		//verif function
		bool    isValidDate();
		bool    isValidNumber();
		bool	isValidHeader();

		//main function
		void	run();


}

#endif  /* BITCOINEXCHANGE_HPP */
