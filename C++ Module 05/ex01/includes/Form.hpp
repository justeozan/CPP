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
		const int			_gradeLevel;

	public:
		Form(void);
		Form(std::string name);
		~Form(void);
		Form&	operator<<(const Form& other);

		std::string	getName() const;
		bool		getSignedStatus() const;
		int			getGradeLevel() const;


		void	maMethode();
};

#endif /* FORM_H */