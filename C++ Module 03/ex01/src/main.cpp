#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int	main(void)
{
	ScavTrap Baelish("LittleFinger");
	ScavTrap Varys("Lord Varys");

	Baelish.displayStatus();
	Varys.displayStatus();

	Baelish.attack(Varys.getName());
	Varys.takeDamage(Baelish.getAttackDamage());
	Varys.beRepaired(20);

	Baelish.displayStatus();
	Varys.displayStatus();
	return (0);
}