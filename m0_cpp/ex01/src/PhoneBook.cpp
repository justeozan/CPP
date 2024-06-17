#include "../includes/header.hpp"

void	PhoneBook::addContact(void)
{
	static int indexContact = 0;

	if (indexContact == 8)
		indexContact = 0;
	_contacts[indexContact].initContact();
	indexContact++;
	return ;
}

void	PhoneBook::displayContacts(void) const
{

	for (int i = 0; i < 8; i++)
	{
		if (_contacts[i].isInitContact())
			_contacts[i].viewContact(i);
	}
}

void	PhoneBook::searchContact(void) const
{

}
