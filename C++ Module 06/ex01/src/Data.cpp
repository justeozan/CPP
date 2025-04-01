
#include "Data.hpp"

Data::Data() : _number(0) {}
Data::~Data() {}

int Data::getNumber() const { return _number; }
void Data::setNumber(int number) { _number = number; }
