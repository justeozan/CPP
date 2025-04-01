
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data data;
    data.setNumber(42);

    std::cout << "Original: " << GREEN << data.getNumber() << RESET << std::endl;
    uintptr_t raw = Serialize::serialize(&data);
    std::cout << "Raw: " << BLUE << raw << RESET << std::endl;
    Data* deserialized = Serialize::deserialize(raw);
    std::cout << "Deserialized: " << GREEN << deserialized->getNumber() << RESET << std::endl;
    return 0;
}