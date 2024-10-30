#ifndef FORM_H
# define FORM_H

/*===========================================*/
/*                 INCLUDES                  */
/*===========================================*/

# include "Bureaucrat.hpp"

/*===========================================*/
/*                  COLORS                   */
/*===========================================*/

# define RESET		"\e[0m"
# define BOLD		"\e[1m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[34m"
# define MAGENTA	"\e[35m"
# define CYAN		"\e[36m"
# define WHITE		"\e[37m"

/*===========================================*/
/*                  CLASS                    */
/*===========================================*/

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_gradeSign;
		int					_gradeExecute;

	public:
		Form(void);
		Form(std::string const name, int const gradeSigne, int const gradeExecute);
		~Form(void);
		Form&			operator=(const Form& other);
		std::ostream&	operator<<(std::ostream& os, const Form& other);

		std::string	getName() const;
		bool		getSignedStatus() const;
		int			getGradeSigne() const;
		int			getGradeExecution() const;


		void	maMethode();

		class	GradeException: public std::exception {};

		class	GradeTooLowException: public GradeException
		{
			public:
				const char* what() const throw();
		};

		class	GradeTooHighException: public GradeException
		{
			public:
				const char* what() const throw();
		};
};

#endif /* FORM_H */