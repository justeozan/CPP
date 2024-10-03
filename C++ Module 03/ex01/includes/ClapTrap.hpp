#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

# define RESET		"\033[0m"
# define RED		"\033[0;31m"
# define WHITE		"\033[37m"
# define GREEN		"\033[32m"
# define BLUE		"\033[0;34m"
# define YELLOW		"\033[0;33m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"

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
		void		displayStatus();

		int			getHitPoints() const;
		int			getEnergyPoints() const;
		int			getAttackDamage() const;
		std::string	getName() const;
};

#endif
