#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other._name)
{
	std::cout << "Copy ScavTrap " << _name << " has been created" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
		std::cout << "ScavTrap " << _name << " has not enough energy or hit points to attack" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "Is in Night's watch mode" << std::endl;
}
