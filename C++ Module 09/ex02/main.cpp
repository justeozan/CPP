#include "PmergeMe.hpp"



int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << RED "Usage: ./PmergeMe <positive integers>..."  RESET << std::endl;
		return 1;
	}

	try {
		PmergeMe sorter;
		sorter.run(av);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}


