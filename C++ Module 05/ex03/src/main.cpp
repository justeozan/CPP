#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"
#include <stdlib.h>

int	main(void)
{
	Intern intern;
	Bureaucrat Tyrioncrat("Tyrion", 3);

	AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Home");
	AForm* robotForm = intern.makeForm("robotomy request", "Chat_GPT3");
	AForm* pardonForm = intern.makeForm("presidential pardon", "Michael");

	std::cout << YELLOW "\n* ----- KO TEST ----- *" RESET << std::endl;
	try {
		std::cout << std::endl;
		Tyrioncrat.signForm(*shrubberyForm);
		Tyrioncrat.executeForm(*shrubberyForm);
	} catch (const std::exception& e) {	std::cout << Tyrioncrat.getName() << " could not execute " << shrubberyForm->getName() << " because " << RED << e.what() << RESET << std::endl;	}

	try {
		std::cout << std::endl;
		Tyrioncrat.signForm(*robotForm);
		Tyrioncrat.executeForm(*robotForm);
	} catch (const std::exception& e) {	std::cout << Tyrioncrat.getName() << " could not execute " << robotForm->getName() << " because " << RED << e .what() << RESET << std::endl;	}

	try {
		std::cout << std::endl;
		Tyrioncrat.signForm(*pardonForm);
		Tyrioncrat.executeForm(*pardonForm);
	} catch (const std::exception& e) {	std::cout << Tyrioncrat.getName() << " could not execute " << pardonForm->getName() << " because " << RED << e.what() << RESET << std::endl;	}
	std::cout << std::endl;

	std::cout << YELLOW "\n* ----- OK TEST ----- *" RESET << std::endl;
	try {

		std::cout << std::endl;
		Tyrioncrat.signForm(*shrubberyForm);
		Tyrioncrat.executeForm(*shrubberyForm);

		std::cout << std::endl;
		Tyrioncrat.signForm(*robotForm);
		Tyrioncrat.executeForm(*robotForm);

		std::cout << std::endl;
		Tyrioncrat.signForm(*pardonForm);
		Tyrioncrat.executeForm(*pardonForm);

		std::cout << std::endl;
	} catch (const std::exception& e) {	std::cout << RED << e.what() << RESET << std::endl;	}
	std::cout << std::endl;

	return (0);
}
