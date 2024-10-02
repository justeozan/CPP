#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Baelish("LittleFinger");
	ClapTrap Varys;

	Baelish.displayStatus();
	Varys.displayStatus();

	Baelish.attack(Varys.getName());
	Varys.takeDamage(Baelish.getAttackDamage());
	Varys.beRepaired(20);

	Baelish.displayStatus();
	Varys.displayStatus();
	return (0);
}
