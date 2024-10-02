#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int 		_hitPoints;
		int 		_energyPoints;
		int 		_attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap& other);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		int			getHitPoints() const;
		int			getEnergyPoints() const;
		int			getAttackDamage() const;
		std::string	getName() const;
		void		displayStatus();
};

#endif
