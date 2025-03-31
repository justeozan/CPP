#include "ScalarConverter.hpp"

int main(int ac, char **av) 
{
    if(ac == 2 && av[1][0] != '\0'){
        try {
            ScalarConverter::convert(av[1]);
            std::cout << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl << std::endl;
        }
    } else
        std::cerr << RED << "Error: bad number of arguments usage: ./scalar_converter <string (not null)>" << RESET << std::endl;
    return 0;
}