#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB() {}

void	HumanB::attack(void)
{
	if (!_weapon)
		std::cout << _name << " cannot attack " << std::endl;
	else
		std::cout << _name << " attack with " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}