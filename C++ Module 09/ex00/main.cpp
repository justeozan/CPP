
#include "BitcoinExchange.hpp"

void	checkArgs(ac) {
	if (ac != 2)
		throw(std::runtime_error("Need the file on second arguments."));
}

int main( void ) {
	try {
		checkArgs(ac);
		BitcoinExchange bEx;
		bEx.registerData("data.csv");
		bEx.registerTransactions("Transactions.csv");


		extract;

		
	} catch (const std::exception& e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return (0);
}