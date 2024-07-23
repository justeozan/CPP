
#include "../includes/Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << "Default Animal has been created" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Copy Animal has been created" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal has been destroyed" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	_type = other._type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "*Animal Sound*" << std::endl;
}

std::string	Animal::getType(void) const
{
	return(_type);
}
