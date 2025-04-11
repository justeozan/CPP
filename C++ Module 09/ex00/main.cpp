
#include "BitcoinExchange.hpp"

void	checkArgs(int ac) {
	if (ac != 2)
		throw(std::runtime_error("Need the file on second arguments."));
}

int main(int ac, char** av) {
	try {
		checkArgs(ac);
		BitcoinExchange bEx;
		// bEx.registerData(av[1]);
		// bEx.registerTransactions(av[1]);

		bEx.run(av[1], "data.csv");

	} catch (const std::exception& e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return (0);
}