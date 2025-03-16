#include "../includes/Bureaucrat.hpp"

#include <stdlib.h>

int	main(void)
{
	try {
		Bureaucrat bureaucrat("Danny", 151);
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat bureaucrat("John", 0);
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat bureaucrat("The king", 1);
		bureaucrat.decrementGrade();
		bureaucrat.incrementGrade();
		bureaucrat.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat bureaucrat("No one", 150);
		bureaucrat.incrementGrade();
		bureaucrat.decrementGrade();
		bureaucrat.decrementGrade();

	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat bureaucrat("test", 79);
		Bureaucrat bureaucrat2(bureaucrat);
		Bureaucrat bureaucrat3("test222", 22);
		bureaucrat3 = bureaucrat2;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
