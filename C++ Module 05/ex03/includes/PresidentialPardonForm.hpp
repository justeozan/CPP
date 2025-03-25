#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

/*===========================================*/
/*                 INCLUDES                  */
/*===========================================*/

#include "Bureaucrat.hpp"
#include <math.h>

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

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);
		PresidentialPardonForm&			operator=(const PresidentialPardonForm& other);

		std::string	getTarget() const;

		void 		execute(const Bureaucrat& executor) const;

};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& other);

#endif /* PRESIDENTIALPARDONFORM_H */