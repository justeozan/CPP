#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <list>

//colors
# define RESET		"\e[0m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[93m"
# define DISCRET	"\e[90m\e[2m\e[3m"


template <typename T>
class MutantStack: public std::stack<T, std::deque<T> >
{
	public:
		typedef std::stack<T, std::deque<T> > classStack;
		typedef typename std::deque<T>::iterator iterator;

		MutantStack() : classStack() { std::cout << DISCRET "creating a MutantStack..." RESET << std::endl; };
		MutantStack(const MutantStack &src) : classStack(src) { std::cout << DISCRET "copying a MutantStack..." RESET; };
		~MutantStack() {}
		MutantStack &operator=(const MutantStack &src) {
			if (this != &src)
				classStack::operator=(src);
			return *this;
		}

		void pop() {
			classStack::pop();
			std::cout << DISCRET "popping one..." << RESET << std::endl;
		}

		void getTopStack(void) {
			std::cout << "stack top: " GREEN << this->c.back() << RESET << std::endl;
		}

		void getStackSize() {
			std::cout << "stack size: " GREEN << this->c.size() << RESET << std::endl;
		}

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

#endif /* MUTANTSTACK_HPP */
