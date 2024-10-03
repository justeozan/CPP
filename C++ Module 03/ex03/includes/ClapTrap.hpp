#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

/*===========================================*/
/*                 INCLUDES                  */
/*===========================================*/

#include <iostream>

/*===========================================*/
/*                  COLORS                   */
/*===========================================*/

# define RESET		"\e[0m"
# define BOLD		"\e[1m"
# define BLACK		"\e[30m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[34m"
# define MAGENTA	"\e[35m"
# define MAGENTA2	"\e[95m"
# define CYAN		"\e[36m"
# define WHITE		"\e[37m"

/*===========================================*/
/*                  CLASS                    */
/*===========================================*/

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
		void		displayStatus(void);

		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		std::string	getName(void) const;
};

#endif /* CLAPTRAP_HPP */
