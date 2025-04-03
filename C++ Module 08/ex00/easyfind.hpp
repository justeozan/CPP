#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::runtime_error(RED"Element not found"RESET);
    return it;
}

#endif  /* EASYFIND_HPP */
