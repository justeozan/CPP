#include "../includes/Zombie.hpp"

Zombie::Zombie(void): _name("unnamed")
{
	std::cout << _name << " is born" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << _name << " is born" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " is dead" << std::endl;
}


void Zombie::announce(void)
{
	std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
