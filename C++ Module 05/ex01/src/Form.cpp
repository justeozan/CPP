#include "Form.hpp"

Form::Form(): _name("*NoName*"), _signed(false), _gradeSign(20), _gradeExecute(10) {}

Form::Form(std::string const name, int const gradeSign, int const gradeExecute): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << "Try to create Form named " << name << " with grade " << gradeSign << " for sign and grade " << gradeExecute << " for execute" << std::endl;
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form " << name << " has been created" << std::endl;
}

Form::Form(const Form& other): _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	std::cout << "Form " << _name << " has been copied" << std::endl;
}

Form::~Form() { std::cout << "Form " << _name << " has been deleted" << std::endl; }

Form&	Form::operator=(const Form& other)
{
	_signed = other._signed;
	return (*this);
}

std::string Form::getName() const { return (_name); }
bool	Form::getSignedStatus() const { return (_signed); }
int	Form::getGradeSigne() const { return (_gradeSign); }
int	Form::getGradeExecution() const { return (_gradeExecute); }


void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooHighException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() { return ("Form has a too high grade"); }
const char* Form::GradeTooLowException::what() const throw() { return ("Form has a too low grade"); }

std::ostream&	operator<<(std::ostream& os, const Form& other)
{
	os << "Form name : " << other.getName()
	<< std::endl << "Is signed : " << other.getSignedStatus()
	<< std::endl << "Grade for Sign : " << other.getGradeSigne()
	<< std::endl << "Grade for Execute : " << other.getGradeExecution() << std::endl;
	return (os);
}