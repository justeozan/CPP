#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
public:
	add_contact();
private:
	Contact contacts[8];
};

#endif