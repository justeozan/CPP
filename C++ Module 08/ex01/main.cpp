#include "iter.hpp"

int main( void ) {
    int tab[] = { 0, 1, 42, 10, -1, 2 };
    ::iter(tab, 6, print<int>);
    std::cout << std::endl;
    std::string tab_of_string[] = { "0", "1", "42", "10", "-1", "2" };
    ::iter(tab_of_string, 6, print<std::string>);
    return 0;
}