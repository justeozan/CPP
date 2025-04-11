#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>


class PmergeMe
{
	private:
		std::list<int> _list;
		std::vector<int> _vector;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe&	operator=(const PmergeMe &src);
		~PmergeMe();

		// Parsing & validation
		void parseInput(char **av);

		// Sorting functions
		void sortVector();
		void sortList();

		// Merge-Insertion logic
		template <typename T>
		void mergeInsertSort(T& container);

		// Display & debug
		void printBefore() const;
		void printAfter() const;

		// Benchmark
		void benchmark();
};

#endif