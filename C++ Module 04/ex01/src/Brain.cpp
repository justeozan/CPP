
#include "../includes/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain has been created" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Copy Brain has been created" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain has been destroyed" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	for (int i = 0; !other._ideas[i][0] ; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

void	Brain::setBrain(std::string idea)
{
	int i = 0;
	while (_ideas[i][0])
		i++;
	if (i < 100)
		_ideas[i] = idea;
}

void	Brain::printBrain()
{
	for (int i = 0; _ideas[i][0] ; i++)
		std::cout << _ideas[i] << std::endl;
}
