#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "Copy ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has not enough energy or hit points to attack" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints - amount < 0 ? 0 : _hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " take " << amount << " points of damage" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is already disabled" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has not enough energy or hit points to repair" << std::endl;
	else
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " heal " << amount << " points of life" << std::endl;
	}
}

int	ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

int	ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

int	ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

std::string	ClapTrap::getName() const
{
	return (_name);
}

void	ClapTrap::displayStatus()
{
	std::cout << std::endl;
	std::cout << _name << std::endl;
	std::cout << "hitPoints: " << _hitPoints << std::endl;
	std::cout << "energyPoints: " << _energyPoints << std::endl;
	std::cout << "attackDamage: " << _attackDamage << std::endl;
	std::cout << std::endl;
}

