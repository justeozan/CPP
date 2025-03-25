#ifndef AFORM_HPP
# define AFORM_HPP

/*===========================================*/
/*                 INCLUDES                  */
/*===========================================*/

#include "Bureaucrat.hpp"

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

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		AForm(void);
		AForm(std::string const name, int const gradeSign, int const gradeExecute);
		AForm(const AForm& other);
		virtual ~AForm(void);
		AForm&			operator=(const AForm& other);

		std::string	getName() const;
		bool		getSignedStatus() const;
		int			getGradeSigne() const;
		int			getGradeExecution() const;

		void 		beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(const Bureaucrat& executor) const = 0;

		class	GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class	GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class	FormNotSignedException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif /* AFORM_HPP */