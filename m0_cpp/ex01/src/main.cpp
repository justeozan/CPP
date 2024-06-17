#include "../includes/header.hpp"

int main(void)
{
	std::string response;
	PhoneBook	book;
	

	while (1)
	{
		std::cout << "que veux tu gros ? [ADD / SEARCH / EXIT] : " << std::flush;
		std::cin >> response;
		if (!response.empty())
			std::cout << response << std::endl;
		if (response == "ADD")
		{	
			book.addContact();
		}
		if (response == "SEARCH")
		{
			book.displayContacts();
			book.searchContact();
		}
		if (response == "EXIT")
			break;

	}
	return 0;
}