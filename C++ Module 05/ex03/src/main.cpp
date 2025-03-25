#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <stdlib.h>

int	main(void)
{
	Bureaucrat dannycrat("Danny", 1);
	Bureaucrat Tyrioncrat("Tyrion", 150);

	ShrubberyCreationForm shrubberyForm("Home");
	RobotomyRequestForm robotForm("Chat_GPT3");
	PresidentialPardonForm pardonForm("Michael");

	std::cout << YELLOW "\n* ----- FAILING TESTS ----- *" RESET << std::endl;
	try {
		std::cout << std::endl;
		Tyrioncrat.signForm(shrubberyForm);
		Tyrioncrat.executeForm(shrubberyForm);
	} catch (const std::exception& e) {	std::cout << Tyrioncrat.getName() << " could not execute " << shrubberyForm.getName() << " because " << RED << e.what() << RESET << std::endl;	}

	try {
		std::cout << std::endl;
		Tyrioncrat.signForm(robotForm);
		Tyrioncrat.executeForm(robotForm);
	} catch (const std::exception& e) {	std::cout << Tyrioncrat.getName() << " could not execute " << robotForm.getName() << " because " << RED << e .what() << RESET << std::endl;	}

	try {
		std::cout << std::endl;
		Tyrioncrat.signForm(pardonForm);
		Tyrioncrat.executeForm(pardonForm);
	} catch (const std::exception& e) {	std::cout << Tyrioncrat.getName() << " could not execute " << pardonForm.getName() << " because " << RED << e.what() << RESET << std::endl;	}
	std::cout << std::endl;

	std::cout << YELLOW "\n* ----- WORKING TESTS ----- *" RESET << std::endl;
	try {
		std::cout << std::endl;
		dannycrat.signForm(shrubberyForm);
		dannycrat.executeForm(shrubberyForm);

		std::cout << std::endl;
		dannycrat.signForm(robotForm);
		dannycrat.executeForm(robotForm);

		std::cout << std::endl;
		dannycrat.signForm(pardonForm);
		dannycrat.executeForm(pardonForm);

		std::cout << std::endl;
	} catch (const std::exception& e) {	std::cout << RED << e.what() << RESET << std::endl;	}
	std::cout << std::endl;

	return (0);
}
