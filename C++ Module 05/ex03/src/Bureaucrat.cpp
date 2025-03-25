#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("No name"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int const grade): _name(name)
{
	std::cout << GREEN "Try to create Bureaucrat named " RESET << name << GREEN " with grade " RESET << grade << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name), _grade(copy._grade) {}

Bureaucrat::~Bureaucrat(void) 
{
	std::cout << "Bureaucrat named " << _name << " with grade " << _grade << " has been destroyed" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1) {
		std::cout << "Bureaucrat named " << _name << " has already the highest grade" << std::endl;
		throw GradeTooHighException();
	}
	_grade--;
	std::cout << "Bureaucrat named " << _name << " has been incremented to grade " << _grade << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150) {
		std::cout << "Bureaucrat named " << _name << " has already the lowest grade" << std::endl;
		throw GradeTooLowException();
	}
	_grade++;
	std::cout << "Bureaucrat named " << _name << " has been decremented to grade " << _grade << std::endl;
}

void Bureaucrat::signForm(AForm &form) const
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " could not sign " << form.getName() << " because "  << RED << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	form.execute(*this);
	std::cout << _name << " executes " << form.getName() << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat has passed the highest born");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat has passed the lowest born");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy) {
		_grade = copy._grade;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() <<  ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}