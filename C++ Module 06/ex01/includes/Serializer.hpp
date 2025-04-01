#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

class Serialize {
    private:
        Serialize();
        ~Serialize();
        Serialize(const Serialize& src);
        Serialize& operator=(const Serialize& src);
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif  /* SERIALIZER_HPP */
