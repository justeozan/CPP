#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other._name)
{
	std::cout << "Copy FragTrap " << _name << " has been created" << std::endl;
	*this = other;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " has been destroyed" << std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
		std::cout << "FragTrap " << _name << " has not enough energy or hit points to attack" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "He do a high five" << std::endl;
}
