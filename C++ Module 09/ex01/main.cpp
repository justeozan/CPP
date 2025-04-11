
#include "RPN.hpp"

int main(int ac, char** av) {
    try {
        if (ac != 2)
            throw std::runtime_error("Wrong number of arguments");
        RPN rpn;
        rpn.calculate(av[1]);
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
    return 0;
}