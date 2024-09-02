#include "../includes/Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac == 2)
		return (harl.complain(av[1]), 0);
	std::cout << "Error: wrong number of arguments" << std::endl;
	return 0;
}
