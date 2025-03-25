#ifndef INTERN_HPP
# define INTERN_HPP

/*===========================================*/
/*                 INCLUDES                  */
/*===========================================*/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*===========================================*/
/*                  COLORS                   */
/*===========================================*/

#define RESET		"\e[0m"
#define BOLD		"\e[1m"
#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define BLUE		"\e[34m"
#define MAGENTA		"\e[35m"
#define CYAN		"\e[36m"
#define WHITE		"\e[37m"

/*===========================================*/
/*                  CLASS                    */
/*===========================================*/

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern(void);
		Intern&			operator=(const Intern& other);

		AForm*	makeForm(std::string const name, std::string const target);
		AForm*	makeShrubberyCreationForm(std::string const target);
		AForm*	makeRobotomyRequestForm(std::string const target);
		AForm*	makePresidentialPardonForm(std::string const target);

		class	UnknownFormException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Intern& other);

#endif /* INTERN_HPP */