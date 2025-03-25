#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("*NoTarget*", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target): AForm(target, 145, 137) {std::cout << BLUE "ShrubberyCreationForm" RESET << std::endl;}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
	std::cout << "ShrubberyCreationForm " << getName() << " has been copied" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout <<  BLUE "ShrubberyCreationForm: " RESET; }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	_target = other._target;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const { return (_target); }

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getSignedStatus())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExecution())
		throw GradeTooHighException();
	std::ofstream file((getName() + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("Cannot open file");
	file << "      ###\n"
         << "     #####\n"
         << "    #######\n"
         << "   #########\n"
         << "  ####0000###\n"
         << "      |||\n"
         << "      |||\n"
         << "      |||\n";
	file.close();
	std::cout << GREEN << getName() <<  "_shrubbery file has been created" RESET << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& other)
{
	os << "ShrubberyCreationForm name : " << other.getName()
	<< std::endl << "Is signed : " << other.getSignedStatus()
	<< std::endl << "Grade for Sign : " << other.getGradeSigne()
	<< std::endl << "Grade for Execute : " << other.getGradeExecution() << std::endl;
	return (os);
}
