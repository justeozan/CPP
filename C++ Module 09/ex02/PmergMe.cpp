#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }
PmergeMe&	PmergeMe::operator=(const PmergeMe &src) { this->_list = src._list; this->_vector = src._vector; return *this; }
PmergeMe::~PmergeMe() {}

void	PmergeMe::parseInput(char **av) {
	for (int i = 1; av[i]; ++i) {
		std::istringstream	iss(av[i]);
		int					n;

		if (!(iss >> n) || n < 0)
			throw std::runtime_error("Invalid input: must be positive integers");
		_list.push_back(n);
		_vector.push_back(n);
	}
}

void	PmergeMe::sortVector() {
	mergeInsertSort(_vector);
}

void	PmergeMe::sortList() {
	mergeInsertSort(_list);
}

void	PmergeMe::mergeInsertSort(T& container) {
	clock_t	start, end;
	std::vector<int> tmpVector = _vector;

	start = clock();
	mergeInsertSort(tmpVector);
	end = clock();
	double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << tmpVector.size() << " elements with std::vector : " << vecTime << " us" << std::endl;

	std::list<int> tmpList = _list;
	start = clock();
	mergeInsertSort(tmpList);
	end = clock();
	double listTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << tmpList.size() << " elements with std::list   : " << listTime << " us" << std::endl;
}	

void	PmergeMe::printBefore() const {
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printAfter() const {
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::benchmark() {
	
}
