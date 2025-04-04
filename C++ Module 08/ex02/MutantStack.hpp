#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
// #include <algorithm>
// #include <exception>
// #include <string>

//colors
#define RESET		"\e[0m"
#define BOLD		"\e[1m"
#define FAINT		"\e[2m"
#define ITALIC		"\e[3m"
#define UNDERLINE	"\e[4m"
#define BLINK		"\e[5m"
#define REVERSE		"\e[7m"
#define HIDDEN		"\e[8m"
#define STRIKETHROUGH	"\e[9m"
#define OVERLINE		"\e[53m"
#define BLACK		"\e[30m"
#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define BLUE		"\e[34m"
#define MAGENTA		"\e[35m"
#define CYAN		"\e[36m"
#define WHITE		"\e[37m"
#define DEFAULT		"\e[39m"
#define GRAY		"\e[90m"
#define DARKRED		"\e[91m"
#define DARKGREEN	"\e[92m"
#define DARKYELLOW	"\e[93m"
#define DARKBLUE		"\e[94m"
#define DARKMAGENTA	"\e[95m"
#define DARKCYAN		"\e[96m"
#define DARKWHITE		"\e[97m"
#define ORANGE		"\e[38;5;166m"


template <typename T>
class MutantStack: public std::stack<T, std::deque<T> >
{
	public:
        typedef std::stack<T, std::deque<T> > classStack;
        typedef typename std::deque<T>::iterator iterator;


		MutantStack() : classStack() {};
		MutantStack(const MutantStack &src) : classStack(src) {};
		~MutantStack() {};
		MutantStack &operator=(const MutantStack &src) {
            if (this != &src)
                classStack::operator=(src);
            return *this;
        }

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
};

#endif /* MUTANTSTACK_HPP */
