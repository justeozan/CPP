
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <ctime>		// for std::tm
# include <map>
# include <fstream>		// for std::ifstream
# include <cstring>		// for memset
# include <sstream>		// for std::istringstream
# include <string>		// for std::string

//colors
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[93m"
# define DISCRET	"\e[90;2;3m"
# define RESET		"\e[0m"

class BitcoinExchange {
	private:
		struct tmCompare {
			bool operator()(const std::tm& lhs, const std::tm& rhs) const {
				if (lhs.tm_year != rhs.tm_year) return lhs.tm_year < rhs.tm_year;
				if (lhs.tm_mon != rhs.tm_mon) return lhs.tm_mon < rhs.tm_mon;
				return lhs.tm_mday < rhs.tm_mday;
			}
		};
		std::map<std::tm, float, tmCompare> _data;
		std::map<std::tm, float, tmCompare> _transactions;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		//file function
		void    registerData(char const* filename);
		void    displayTransactions(char const* filename);

		//verif function
		void		check(bool condition, std::string message);
		std::tm		parseDate(std::string date);
		float		parseRate(std::string number);

		//display function
		void		displayValues(std::string date, std::string amount);

		//main function
		void	run(char const* transFile, char const* filename);

		//debug function
		void	printData() const;
};

#endif  /* BITCOINEXCHANGE_HPP */
