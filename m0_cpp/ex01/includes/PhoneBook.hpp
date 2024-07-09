#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "header.hpp"

/**
 * @brief The PhoneBook class.
 * This class allows me to create a phone book of eight contacts.
 * It allows me to add, display and search for contacts.
 */
class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void	addContact(void);
	void	displayContacts(void) const;
	void	searchContact(void) const;
	
private:
	Contact _contacts[8];
};

#endif