#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "header.hpp"

class PhoneBook {
public:
	void	addContact(void);
	void	displayContacts(void) const;
	void	searchContact(void) const;
	
private:
	Contact _contacts[8];
};

#endif