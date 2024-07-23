
#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "Default WrongCat has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	*this = other;
	std::cout << "Copy WrongCat has been created" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat has been destroyed" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	_type = other._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*Wrong Miawww Miawww*" << std::endl;
}
