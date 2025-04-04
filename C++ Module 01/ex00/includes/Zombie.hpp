#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

/**
 * @brief Class Zombie, a class that represents a zombie, with a name and a function to announce itself
 */
class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};

Zombie*	newZombie(std::string name);
void 	randomChump(std::string name);

#endif