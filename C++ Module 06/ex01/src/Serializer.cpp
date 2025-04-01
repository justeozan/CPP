#include "Serializer.hpp"

Serialize::Serialize() {}
Serialize::~Serialize() {}

uintptr_t Serialize::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialize::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}

Serialize& Serialize::operator=(const Serialize& src) {
    (void)src;
    return (*this);
}   

Serialize::Serialize(const Serialize& src) {
    (void)src;
}
