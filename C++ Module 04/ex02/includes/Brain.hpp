#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain(void);
		Brain(const Brain& other);
		~Brain(void);
		Brain&	operator=(const Brain& other);

		void	setBrain(std::string idea);
		void	printBrain(void);
};

#endif