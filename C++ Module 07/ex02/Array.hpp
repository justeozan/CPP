#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

//colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;

    public:
        Array(): _size(0) { _array = new T[0]; }
        Array(unsigned int n): _size(n) { _array = new T[n]; }
        Array(const Array &src): _size(src._size) {
            _array = new T[src._size];
            for (unsigned int i = 0; i < src._size; i++) {
                _array[i] = src._array[i];
            }
        }
        ~Array() { delete[] _array; }

        Array &operator=(const Array &src) {
            _size = src._size;
            _array = new T[src._size];
            for (unsigned int i = 0; i < src._size; i++) {
                _array[i] = src._array[i];
            }
            return *this;
        }

        T &operator[](unsigned int index) {
            if (index >= _size) {
                throw std::out_of_range("Index out of range");
            }
            return _array[index];
        }

        const T &operator[](unsigned int index) const {
            if (index >= _size) {
                throw std::out_of_range("Index out of range");
            }
            return _array[index];
        }

        unsigned int getSize() const { return _size; }
};

#endif  /* ARRAY_HPP */