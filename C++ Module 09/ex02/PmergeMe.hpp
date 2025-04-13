#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>

# define RED		"\e[31m"
# define BLUE		"\e[34m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[93m"
# define DISCRET	"\e[90;2;3m"
# define RESET		"\e[0m"

class PmergeMe
{
	private:
		std::list<int> _list;
		std::vector<int> _vector;

		PmergeMe(const PmergeMe &src);
		PmergeMe&	operator=(const PmergeMe &src);

		void parseInput(char **av);
		void printNumbers(std::string str) const;
		void benchmark();
		
		// Jacobsthal helper
		std::vector<int> generateJacobsthalIndices(int size) const;

		// Helpers
		int		getNth(const std::list<int>& lst, int n);
		int		getNth(const std::vector<int>& vec, int n);
		void	insertSorted(std::list<int>& lst, int value);
		void	insertSorted(std::vector<int>& vec, int value);
		
		template <typename T>
		void sort(T& container) {
			if (container.size() <= 1)
				return;
		
			typedef typename T::iterator It;
			T pairs;
			T unpaired;
		
			It it = container.begin();
			while (it != container.end()) {
				It next = it;
				++next;
				if (next != container.end()) {
					if (*it < *next) {
						pairs.push_back(*next);
						unpaired.push_back(*it);
					} else {
						pairs.push_back(*it);
						unpaired.push_back(*next);
					}
					++it; ++it;
				} else {
					pairs.push_back(*it);
					++it;
				}
			}
		
			sort(pairs);
		
			std::vector<int> indices = generateJacobsthalIndices(unpaired.size());
			std::vector<bool> inserted(unpaired.size(), false);
		
			container = pairs;
		
			for (std::vector<int>::size_type i = 0; i < indices.size(); ++i) {
				int idx = indices[i];
				if (idx < static_cast<int>(unpaired.size()) && !inserted[idx]) {
					inserted[idx] = true;
					int value = getNth(unpaired, idx);
					insertSorted(container, value);
				}
			}
			for (std::vector<int>::size_type i = 0; i < unpaired.size(); ++i) {
				if (!inserted[i]) {
					int value = getNth(unpaired, i);
					insertSorted(container, value);
				}
			}
		}
		
	public:
		PmergeMe();
		~PmergeMe();
		
		void run(char **av);
};



#endif