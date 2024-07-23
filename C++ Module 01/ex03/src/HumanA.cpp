
#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {}

HumanA::~HumanA()
{
	
}

void	HumanA::attack(void)
{
	std::cout << _name << " attack with " << _weapon.getType() << std::endl;
}
