#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <stdlib.h>

int	main(void)
{
	try {
		Form form("form", 0, 15);
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	try {
		Form form("form", 15, 151);
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat dannycrat("Danny", 89);
		Form drogon("Vente de Drogon", 66, 66);
		dannycrat.signForm(drogon);
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat johnycrat("John", 15);
		Form Rhaegal("Adoption de Rhaegal", 77, 77);
		johnycrat.signForm(Rhaegal);
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat nolaycrat("Nolay", 150);
		Form form("form", 150, 150);
		std::cout << "Before sign : " << form.getSignedStatus() << std::endl;
		form.beSigned(nolaycrat);
		std::cout << "After sign : " << form.getSignedStatus() << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
