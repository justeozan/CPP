#include "easyfind.hpp"

int main( void ) {
	std::vector<int> vec;
	for(int i = 0; i < 5; i++)
		vec.push_back(i * 10);
	std::cout << "Vector: ";
	for (int i = 0; i < 5; i++)
		std::cout << vec[i] << ' ';
	std::cout << "\n" << std::endl;
	try {
		std::cout << BOLD << "Search 30: " << RESET << std::endl;
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << GREEN << *it << RESET << std::endl;
		std::cout << BOLD << "Search 35: " << RESET << std::endl;
		it = easyfind(vec, 35);
		std::cout << GREEN << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return 0;
}