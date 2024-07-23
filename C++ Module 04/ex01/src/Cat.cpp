
#include "../includes/Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	_brain = new Brain;
	_brain->setBrain("Eat");
	_brain->setBrain("Drink milk");
	_brain->setBrain("Sleep");
	std::cout << "Default Cat has been created" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	*this = other;
	std::cout << "Copy Cat has been created" << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat has been destroyed" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	_type = other._type;
	_brain = new Brain(*other._brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "*Miawww Miawww*" << std::endl;
}

void	Cat::printBrain()
{
	_brain->printBrain();
}
