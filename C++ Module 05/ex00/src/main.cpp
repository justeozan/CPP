#include "../includes/Bureaucrat.hpp"

#include <stdlib.h>

int	main(int ac, char **av)
{
	for (int i = 1; i < ac; i += 2)
	{
		Bureaucrat bureaucrat(av[i], atoi(av[i + 1]));
		std::cout << std::endl;
		std::cout << "\nname : " << bureaucrat.getName() << "\ngrade : " << bureaucrat.getGrade() << std::endl;
		std::cout << std::endl;
		if ( i % 2 == 0)
			bureaucrat.incrementGrade();
		else
			bureaucrat.decrementGrade();
		std::cout << "name : " << bureaucrat.getName() << "\ngrade : " << bureaucrat.getGrade() << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
