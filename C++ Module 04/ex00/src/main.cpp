#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << std::endl;
	std::cout << animal->getType() << std::endl;
	animal->makeSound();
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	std::cout << std::endl;
	
	delete animal;
	delete cat;
	delete dog;
	delete wrongCat;
	return (0);
}