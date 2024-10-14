#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(const Animal& other);
		virtual ~Animal(void);
		Animal&	operator=(const Animal& other);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif