#include "../includes/header.hpp"

int main(void)
{
	std::string response;
	PhoneBook	book;
	

	while (1)
	{
		std::cout << "que veux tu gros ? [ADD / SEARCH / EXIT] : " << std::flush;
		std::cin >> response;
		// if (!response.empty())
		// 	std::cout << response << std::endl;
		if (response == "ADD" || response == "1")
		{	
			book.addContact();
		}
		if (response == "SEARCH" || response == "2")
		{
			book.displayContacts();
			book.searchContact();
		}
		if (response == "EXIT" || response == "3")
			break;

	}
	return 0;
}