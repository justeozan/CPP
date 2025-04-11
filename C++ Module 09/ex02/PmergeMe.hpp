#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>


class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe&	operator=(const PmergeMe &src);
		~PmergeMe();

		void	calculate(std::string input);

	private:
		std::list<int> _list;
		std::vector<int> _vector;
};

#endif