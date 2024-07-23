
#include "../includes/Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain;
	_brain->setBrain("Eat Bones");
	_brain->setBrain("Drink water");
	_brain->setBrain("Sleep");
	std::cout << "Default Dog has been created" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
	*this = other;
	std::cout << "Copy Dog has been created" << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog has been destroyed" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	_type = other._type;
	_brain = new Brain(*other._brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "*OUUAAFFF OUUAAFFF*" << std::endl;
}

void	Dog::printBrain()
{
	_brain->printBrain();
}

