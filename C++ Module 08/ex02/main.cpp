#include "MutantStack.hpp"

void printBar() {
	std::cout << YELLOW << "\n=====================================================" << RESET << std::endl;
}

void printTest(std::string msg) {
	std::cout << YELLOW << "\n-- " << msg << " --" << RESET << std::endl;
}

void printPush(std::string val) {
	std::cout << DISCRET "pushing "<< val << " ..." RESET << std::endl;
}

int main()
{
	printBar();
	// ====== test print the top ======
	printTest("test print the top");
	MutantStack<int> mstack;
	printPush("5, 17");
	mstack.push(5);
	mstack.push(17);
	mstack.getTopStack(); // normally 17
	mstack.pop();
	mstack.getTopStack(); // normally 5
	mstack.pop();
	mstack.getStackSize(); // normally 0

	// ====== test print the iterator ======
	printTest("test print the iterator");
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	printPush("3, 5, 737, 0");
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << GREEN << *it << ' ' << RESET; // normally 3 5 737 0
	std::cout << std::endl;
	MutantStack<int> s(mstack);

	// ====== test print the copy stack ======
	printTest("test print the copy stack");
	for (MutantStack<int>::iterator it = s.begin(); it != s.end(); ++it)
		std::cout << GREEN << *it << ' ' << RESET; // normally 3 5 737 0
	std::cout << std::endl;

	printBar();
	// ====== test print the top ======
	std::list<int> lstack;
	std::cout << YELLOW << "\n-- test print the top --\n" << DISCRET "creating a std::list<int>...\npushing 5, 17..." << RESET << std::endl;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << "lstack.top(): " << GREEN << lstack.back() << DISCRET "\npopping one..." << RESET << std::endl;
	lstack.pop_back();
	std::cout << "lstack.top(): " << GREEN << lstack.back() << DISCRET "\npopping one..." << RESET << std::endl;
	lstack.pop_back();
	std::cout << "lstack.size(): " << GREEN << lstack.size() << RESET << std::endl; // normally 0

	// ====== test print the iterator ======
	printTest("test print the iterator");
	printPush("3, 5, 737, 0");
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);
	for (std::list<int>::iterator it = lstack.begin(); it != lstack.end(); ++it)
		std::cout << GREEN << *it << ' ' << RESET; // normally 3 5 737 0
	std::cout << std::endl;
	std::stack<int> s2;
	for (std::list<int>::iterator it = lstack.begin(); it != lstack.end(); ++it)
		s2.push(*it);

	// ====== test print the copy stack ======
	printTest("test print the copy stack");
	std::cout << DISCRET "creating a copy stack from the std::list<int>..." << RESET << std::endl;
	for (std::list<int>::iterator lit = lstack.begin(); lit != lstack.end(); ++lit)
		std::cout << GREEN << *lit << ' ' << RESET; // normally 3 5 737 0
	std::cout << std::endl;

	return 0;
}


