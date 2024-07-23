#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

int main()
{
	{
		int i = 10;
		Animal *animals[i];
		for (int j = 0; j < i / 2; j++)
		{
			std::cout << j + 1 << std::endl;
			animals[j] = new Dog();
			std::cout << std::endl;
		}
		for (int j = i / 2; j < i; j++)
		{
			std::cout << j + 1 << std::endl;
			animals[j] = new Cat();
			std::cout << std::endl;
		}
		for (int j = 0; j < i; j++)
		{
			std::cout << animals[j]->getType() << ": " << std::flush;
			animals[j]->makeSound();
		}
		std::cout << std::endl;
		for (int j = 0; j < i; j++)
		{
			delete animals[j];
			std::cout << std::endl;
		}
	}
	{
		Dog	dog;
		std::cout << std::endl;
		Cat cat;

		std::cout << std::endl;
		std::cout << dog.getType() << ":" << std::endl;
		dog.printBrain();
		std::cout << std::endl;
		std::cout << cat.getType() << ":" << std::endl;
		cat.printBrain();
		std::cout << std::endl;
	}
}