#include "AForm.hpp"

AForm::AForm(): _name("*NoName*"), _signed(false), _gradeSign(20), _gradeExecute(10) {}

AForm::AForm(std::string const name, int const gradeSign, int const gradeExecute): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << "Try to create AForm named " << name << " with grade " << gradeSign << " for sign and grade " << gradeExecute << " for execute" << std::endl;
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm " << name << " has been created: ";
}

AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	std::cout << "AForm " << _name << " has been copied" << std::endl;
}

AForm::~AForm() { std::cout << "AForm " << _name << " has been deleted" << std::endl; }

AForm&	AForm::operator=(const AForm& other)
{
	_signed = other._signed;
	return (*this);
}

std::string AForm::getName() const { return (_name); }
bool	AForm::getSignedStatus() const { return (_signed); }
int	AForm::getGradeSigne() const { return (_gradeSign); }
int	AForm::getGradeExecution() const { return (_gradeExecute); }


void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooHighException();
	_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() { return ("Form has a too high grade"); }
const char* AForm::GradeTooLowException::what() const throw() { return ("Form has a too low grade"); }
const char* AForm::FormNotSignedException::what() const throw() { return ("Form has not been signed"); }

std::ostream&	operator<<(std::ostream& os, const AForm& other)
{
	os << "AForm name : " << other.getName()
	<< std::endl << "Is signed : " << other.getSignedStatus()
	<< std::endl << "Grade for Sign : " << other.getGradeSigne()
	<< std::endl << "Grade for Execute : " << other.getGradeExecution() << std::endl;
	return (os);
}