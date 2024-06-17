#include "../includes/header.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

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
	std::cout << "---- PHONEBOOK CONTACTS ----" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (_contacts[i].isInitContact())
			_contacts[i].viewContact(i);
	}
}

void	PhoneBook::searchContact(void) const
{
	int i;

	std::cout << "Please enter the number of a contact : ";
	if (std::cin >> i && i < 8 && i > -1)
		_contacts[i].printContact(i);
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Error : Invalid entry." << std::endl;
	}
}
