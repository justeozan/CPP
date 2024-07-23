#include "../includes/Zombie.hpp"

int main(void)
{
	int n = 15;
	Zombie *horde = zombieHorde(n, "Zombian");

	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
