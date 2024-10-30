

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int const grade): _name(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		_grade = grade;
	}
	catch (const GradeException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(void)
{

}

std::string Bureaucrat::getName(void)
{
	return (_name);
}

int	Bureaucrat::getGrade(void)
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade == 1)
			throw GradeTooHighException();
		std::cout << "Incrementing..." << std::endl;
		_grade--;
	}
	catch (const GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade == 150)
			throw GradeTooLowException();
		std::cout << "Decrementing..." << std::endl;
		_grade++;
	}
	catch (const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("You've depassed the highest born");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("You've depassed the lowest born");
}
