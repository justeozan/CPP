#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"

template <typename T>
void iter(T *array, int length, void (*f)(T&)) {
    for ( int i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void print(T& x) {
    std::cout << GREEN << x << ", " << RESET;
}

#endif  /* WHATEVER_HPP */
