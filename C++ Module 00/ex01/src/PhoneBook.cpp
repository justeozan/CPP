#include "../includes/header.hpp"

/**
 * @brief Constructor of my PhoneBook class.
 * Allows me to initialize variables beforehand.
 */
PhoneBook::PhoneBook()
{

}

/**
 * @brief Destructor of my PhoneBook class.
 * This allows me to free resources if needed.
 */
PhoneBook::~PhoneBook()
{

}

/**
 * @brief Adds a contact to the phone book.
 */
void	PhoneBook::addContact(void)
{
	static int indexContact = 0;

	if (indexContact == 8)
		indexContact = 0;
	_contacts[indexContact].initContact();
	indexContact++;
	return ;
}

/**
 * @brief Displays the contacts in the phone book.
 */
void	PhoneBook::displayContacts(void) const
{
	std::cout << std::endl;
	std::cout << "---- PHONEBOOK CONTACTS ----" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (_contacts[i].isInitContact())
			_contacts[i].viewContact(i);
	}
}

/**
 * @brief Searches for a contact in the phone book.
 */
void	PhoneBook::searchContact(void) const
{
	int i;

	std::cout << std::endl;
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
