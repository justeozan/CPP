#include "Form.hpp"


Form::Form(): _name("*NoName*"), _gradeSign(20), _gradeExecute(10), _signed(false) {}

Form::Form(std::string const name, int const gradeSign, int const gradeExecute): _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	try
	{
		if (gradeSign < 1)
			throw GradeTooLowException();
		else if (gradeSign > 150)
			throw GradeTooHighException();
		std::cout << "Form " << _name << " has been created" << std::endl;

	}
	catch (const GradeException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Form::~Form()
{
	std::cout << "Form " << _name << " has been deleted" << std::endl;
}

Form&	Form::operator=(const Form& other)
{
	_signed = other._signed;
	return (*this);
}

std::ostream&	Form::operator<<(std::ostream& os, const Form& other)
{
	std::cout << "Form name : " << other.getName() << std::endl;
	std::cout << "Is signed : " << (other.getSignedStatus() ? "Yes (" : "No (") << other.getSignedStatus() << ")" << std::endl;
	std::cout << "Grade for Sign : " << other.getGradeSigne() << std::endl;
	std::cout << "Grade for Execute : " << other.getGradeExecution() << std::endl;
	return (os);
}


