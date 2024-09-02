#include "../includes/Zombie.hpp"

/**
 * @note The name of the zombies will be the same as the name parameter
 * And delete with [] is for deleting arrays
*/
int main(void)
{
	int n = 15;
	Zombie *horde = zombieHorde(n, "Zombian");

	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
