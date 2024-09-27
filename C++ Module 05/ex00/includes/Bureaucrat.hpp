#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		int			_grade;
		std::string	_name;

	public:
		Bureaucrat(std::string const name, int const grade);
		~Bureaucrat(void);

		std::string	getName();
		int			getGrade();

		void		incrementGrade();
		void		decrementGrade();

		class GradeException: public std::exception {};

		class GradeTooHighException: public GradeException
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public GradeException
		{
			public:
				const char* what() const throw();
		};
};



#endif /* BUREAUCRAT_HPP */