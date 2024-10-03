#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	_name = "Unnamed";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << MAGENTA "DiamondTrap " << _name << " has been created" RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << MAGENTA "DiamondTrap " << _name << " has been created" RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	std::cout << MAGENTA "Copy DiamondTrap " << _name << " has been created" RESET << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << MAGENTA "DiamondTrap " << _name << " has been destroyed" RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
		std::cout << CYAN "DiamondTrap " << _name << " has not enough energy or hit points to attack" RED << std::endl;
	else
	{
		_energyPoints--;
		std::cout << GREEN "DiamondTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" RESET << std::endl;
	}
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My Diamond name is " << _name << std::endl;
}