#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

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

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);
		RobotomyRequestForm&			operator=(const RobotomyRequestForm& other);

		std::string	getTarget() const;

		void		execute(const Bureaucrat& executor) const;


};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& other);

#endif /* ROBOTOMYREQUESTFORM_H */