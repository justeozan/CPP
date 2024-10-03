#include "DiamondTrap.hpp"

int	main(void)
{
	ScavTrap Baelish("LittleFinger");
	DiamondTrap Jon("The King of the north");

	Baelish.displayStatus();
	Jon.displayStatus();

	Baelish.attack(Jon.getName());
	Jon.takeDamage(Baelish.getAttackDamage());
	Jon.beRepaired(20);

	Baelish.displayStatus();
	Jon.displayStatus();
	return (0);
}
