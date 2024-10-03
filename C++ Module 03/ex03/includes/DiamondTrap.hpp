#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
		int 		_hitPoints;
		int 		_energyPoints;
		int 		_attackDamage;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap(void);
		DiamondTrap&	operator=(const DiamondTrap& other);

		void		attack(const std::string& target);
		void		whoAmI(void);
};

#endif /* DIAMONDTRAP_HPP */