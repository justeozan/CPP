#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {
    private:
        int _number;
    public:
        Data();
        ~Data();
        int getNumber() const;
        void setNumber(int number);
};

std::ostream& operator <<(std::ostream& o, const Data& data);

#endif  /* DATA_HPP */