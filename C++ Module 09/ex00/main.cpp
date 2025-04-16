
#include "BitcoinExchange.hpp"

void	checkArgs(int ac) {
	if (ac != 2)
	throw(std::runtime_error("Need the file on second arguments."));
}

int main(int ac, char** av) {
	try {
		checkArgs(ac);
		BitcoinExchange bEx;
		bEx.run(av[1], "data.csv");
	} catch (const std::exception& e) {
		std::cout << RED "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	return (0);
}