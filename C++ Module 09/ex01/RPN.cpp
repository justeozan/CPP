#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &src) { *this = src; }
RPN&	RPN::operator=(const RPN &src) { this->_stack = src._stack; return *this; }
RPN::~RPN() {}

void	RPN::calculate(std::string input) {
	std::istringstream iss(input);
	std::string token;

	while (iss >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (_stack.size() < 2)
				throw std::runtime_error("Not enough operands");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			if (token == "+")
				_stack.push(a + b);
			else if (token == "-")
				_stack.push(a - b);
			else if (token == "*")
				_stack.push(a * b);
			else {
				if (b == 0)
					throw std::runtime_error("Division by zero");
				_stack.push(a / b);
			}
		} else {
			int value;
			std::istringstream iss(token);
			iss >> value;
			if (isprint(token[0]) && !isdigit(token[0]))
				throw std::runtime_error("Invalid operand");
			_stack.push(value);
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Too many operands");
	std::cout << _stack.top() << std::endl;
}
