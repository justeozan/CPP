#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }
PmergeMe&	PmergeMe::operator=(const PmergeMe &src) { this->_list = src._list; this->_vector = src._vector; return *this; }
PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(char **av) {
	for (int i = 1; av[i]; ++i) {
		std::istringstream iss(av[i]);
		int n;
		if (!(iss >> n) || n < 0)
			throw std::runtime_error("Invalid input: must be positive integers");
		_list.push_back(n);
		_vector.push_back(n);
	}
}

void PmergeMe::printNumbers(std::string str) const {
	std::cout << BLUE << str << ": ";
	if (_vector.size() <= 20)
		for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
			std::cout << *it << " ";
	else {
		std::vector<int>::const_iterator it = _vector.begin();
		for (int i = 0; i < 3 ; ++i)
			std::cout << *it++ << " ";
		std::cout << "[...]";
		it = _vector.end();
		it -= 5;
		for (int i = 0; i < 3 ; ++i)
			std::cout << " " << *it++;
	}
	std::cout << RESET << std::endl;
}

void PmergeMe::run(char **av) {
	parseInput(av);
	printNumbers("Before");
	sort(_vector);
	printNumbers("After");
	sort(_list);
	benchmark();
}

void PmergeMe::benchmark() {
	clock_t start, end;

	std::vector<int> tmpVector = _vector;
	start = clock();
	sort(tmpVector);
	end = clock();
	double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 100;
	std::cout << GREEN "Time to process a range of " << tmpVector.size()
			  << " elements with std::vector : " YELLOW << vecTime << " us" RESET << std::endl;

	std::list<int> tmpList = _list;
	start = clock();
	sort(tmpList);
	end = clock();
	double listTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 100;
	std::cout << GREEN "Time to process a range of " << tmpList.size()
			  << " elements with std::list   : " YELLOW << listTime << " us" RESET << std::endl;
}

// Jacobsthal helper
std::vector<int> PmergeMe::generateJacobsthalIndices(int size) const {
	std::vector<int> sequence;
	int j1 = 1, j2 = 0, index = 1;
	while (j1 < size) {
		sequence.push_back(j1);
		int next = j1 + 2 * j2;
		j2 = j1;
		j1 = next;
		++index;
	}
	return sequence;
}

// Helpers
int PmergeMe::getNth(const std::list<int>& lst, int n) {
	std::list<int>::const_iterator it = lst.begin();
	std::advance(it, n);
	return *it;
}

int PmergeMe::getNth(const std::vector<int>& vec, int n) {
	return vec[n];
}

void PmergeMe::insertSorted(std::list<int>& lst, int value) {
	std::list<int>::iterator it = lst.begin();
	while (it != lst.end() && *it < value)
		++it;
	lst.insert(it, value);
}

void PmergeMe::insertSorted(std::vector<int>& vec, int value) {
	std::vector<int>::iterator it = vec.begin();
	while (it != vec.end() && *it < value)
		++it;
	vec.insert(it, value);
}
