
#include "../includes/Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << "Default Dog has been created" << std::endl;
}

Dog::Dog(const Dog& other)
{
	*this = other;
	std::cout << "Copy Dog has been created" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog has been destroyed" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	_type = other._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "*OUUAAFFF OUUAAFFF*" << std::endl;
}
