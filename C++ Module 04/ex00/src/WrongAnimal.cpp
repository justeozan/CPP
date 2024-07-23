
#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << "Default WrongAnimal has been created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
	std::cout << "Copy WrongAnimal has been created" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal has been destroyed" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	_type = other._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*WrongAnimal Sound*" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return(_type);
}
