#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int	main(void)
{
	ScavTrap Baelish("LittleFinger");
	FragTrap Varys("Lord Varys");

	Baelish.displayStatus();
	Varys.displayStatus();

	Baelish.attack(Varys.getName());
	Varys.takeDamage(Baelish.getAttackDamage());
	Varys.beRepaired(20);

	Baelish.displayStatus();
	Varys.displayStatus();
	return (0);
}
