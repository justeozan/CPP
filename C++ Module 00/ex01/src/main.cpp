#include "../includes/header.hpp"

/**
 * @brief Main function of the program.
 */
int	main(void)
{
	std::string response;
	PhoneBook	book;

	while (1)
	{
		std::cout << "What would you like to do? [ADD / SEARCH / EXIT]: " << std::flush;
		std::cin >> response;
		if (!std::cin)
		{
			std::cout << std::endl;
			std::cin.clear();
			std::cout << GREEN "EXIT" RESET << std::endl;
			break ;
		}
		if (response == "ADD" || response == "1")
			book.addContact();
		if (response == "SEARCH" || response == "2")
		{
			book.displayContacts();
			book.searchContact();
		}
		if (response == "EXIT" || response == "3")
		{
			std::cout << GREEN "EXIT" RESET << std::endl;
			break;
		}

	}
	return 0;
}
