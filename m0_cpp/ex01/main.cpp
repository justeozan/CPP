#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>


int main(void)
{
	std::string response;

	while (1)
	{
		std::cout << "que veux tu gros ? [ADD / SEARCH / EXIT] : " << std::flush;
		std::cin >> response;
		if (!response.empty())
			std::cout << response << std::endl;
		if (response == "ADD")
		{	
			add_contact();
		}
		if (response == "SEARCH")
		{
			search_contact();
		}
		if (response == "EXIT")
			break;

	}
	return 0;
}