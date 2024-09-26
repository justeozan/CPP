#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

	public:
		Bureaucrat(std::string const name, int const grade);
		~Bureaucrat(void);

		std::string	getName();
		int			getGrade();



		
};

#endif /* BUREAUCRAT_HPP */