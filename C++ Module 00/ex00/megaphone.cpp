#include <iostream>

int	main(int ac, char **av)
{
	std::string	str;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; av[i]; i++)
		{
			str = av[i];
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)toupper(str[j]);
		}
	std::cout << std::endl;
	return 0;
}
