#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int const grade);
		Bureaucrat(Bureaucrat const& copy);
		Bureaucrat& operator=(Bureaucrat const& copy);

		~Bureaucrat(void);

		std::string	getName() const;
		int			getGrade() const;

		void		incrementGrade();
		void		decrementGrade();

		// class GradeException: public std::exception {};

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);



#endif /* BUREAUCRAT_HPP */