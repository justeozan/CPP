

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int const grade): _grade(grade), _name(name)
{

}

Bureaucrat::~Bureaucrat(void)
{

}

std::string Bureaucrat::getName(void)
{
	return (_name);
}

int Bureaucrat::getGrade(void)
{
	return (_grade);
}

Bureaucrat::Increment
Bureaucrat::Decrement
