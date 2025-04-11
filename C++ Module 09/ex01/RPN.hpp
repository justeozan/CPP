#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[93m"
# define DISCRET	"\e[90;2;3m"
# define RESET		"\e[0m"


class RPN {
	private:
        std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &src);
		RPN&	operator=(const RPN &src);
		~RPN();

		void	calculate(std::string input);
};


#endif