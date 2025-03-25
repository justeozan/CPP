#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& other) { (void)other; }

Intern::~Intern(void) {}

Intern&	Intern::operator=(const Intern& other) { (void)other; return (*this); }

AForm*	Intern::makeForm(std::string const name, std::string const target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm* (Intern::*formCreators[3])(std::string const target) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*formCreators[i])(target));
		}
	}

	throw Intern::UnknownFormException();

	return (NULL);

}

AForm*	Intern::makeShrubberyCreationForm(std::string const target) {
	if (target.empty())
		throw Intern::UnknownFormException();
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyRequestForm(std::string const target) {
	if (target.empty())
		throw Intern::UnknownFormException();
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialPardonForm(std::string const target) {
	if (target.empty())
		throw Intern::UnknownFormException();
	return (new PresidentialPardonForm(target));
}

const char* Intern::UnknownFormException::what() const throw() { return ("Unknown form"); }


std::ostream&	operator<<(std::ostream& os, const Intern& other)
{
	os << "Intern" << std::endl;
	(void)other;
	return (os);
}