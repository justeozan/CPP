#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	
	std::cout << animal->getType() << std::endl;
	animal->makeSound();
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << dog->getType() << std::endl;
	dog->makeSound();
	
	delete animal;
	delete cat;
	delete dog;
	return (0);
}