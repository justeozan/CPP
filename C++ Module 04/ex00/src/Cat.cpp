
#include "../includes/Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << "Default Cat has been created" << std::endl;
}

Cat::Cat(const Cat& other)
{
	*this = other;
	std::cout << "Copy Cat has been created" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat has been destroyed" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	_type = other._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "*Miawww Miawww*" << std::endl;
}
