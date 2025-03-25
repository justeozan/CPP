#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("*NoName*", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const target): AForm(target, 25, 5) { std::cout << BLUE "PresidentialPardonForm" RESET << std::endl; }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{
	std::cout << "PresidentialPardonForm " << other.getName() << " has been copied" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << BLUE "PresidentialPardonForm: " RESET; }

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	_target = other._target;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const { return (_target); }

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getSignedStatus())
		throw PresidentialPardonForm::FormNotSignedException();
	if (executor.getGrade() > getGradeExecution())
		throw PresidentialPardonForm::GradeTooHighException();
	std::cout << GREEN << getName() << " has been pardoned by Zafod Beeblebrox" RESET << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& other)
{
	os << "PresidentialPardonForm name : " << other.getName()
	<< std::endl << "Is signed : " << other.getSignedStatus()
	<< std::endl << "Grade for Sign : " << other.getGradeSigne()
	<< std::endl << "Grade for Execute : " << other.getGradeExecution() << std::endl;
	return (os);
}
