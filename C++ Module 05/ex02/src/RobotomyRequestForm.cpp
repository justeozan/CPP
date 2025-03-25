#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("*NoTarget*", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const target): AForm(target, 72, 45) { std::cout << BLUE "RobotomyRequestForm" RESET << std::endl; }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other)
{
	std::cout << "RobotomyRequestForm " << getName() << " has been copied" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << BLUE "RobotomyRequestForm: " RESET; }

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	_target = other._target;
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const { return (_target); }

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!getSignedStatus())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExecution())
		throw GradeTooHighException();
	std::cout << "*Makes some drilling noises*" << std::endl;
	if (rand() % 2)
		std::cout << GREEN << getName() << " has been robotomized successfully" RESET << std::endl;
	else
		std::cout << RED << getName() <<  " robotomization failed" RESET << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& other)
{
	os << "RobotomyRequestForm name : " << other.getName()
	<< std::endl << "Is signed : " << other.getSignedStatus()
	<< std::endl << "Grade for Sign : " << other.getGradeSigne()
	<< std::endl << "Grade for Execute : " << other.getGradeExecution() << std::endl;
	return (os);
}
