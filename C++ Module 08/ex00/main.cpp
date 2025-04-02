#include "easyfind.hpp"

int main( void ) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = easyfind(vec, 3);
    std::cout << *it << std::endl;
    return 0;
}