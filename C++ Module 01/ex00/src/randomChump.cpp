#include "../includes/Zombie.hpp"

/**
 * @brief Function that creates a zombie on the stack and makes it announce itself
 * @note The stack zombie will be destroyed when the function ends
 * @param name The name of the zombie
 */
void	randomChump(std::string name)
{
	Zombie randomZombie(name);
	randomZombie.announce();
}
