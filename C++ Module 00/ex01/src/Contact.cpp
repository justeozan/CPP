#include "../includes/header.hpp"

/**
 * @brief Constructor of my Contact class.
 * Allows me to initialize variables beforehand.
 */
Contact::Contact() : _first_name("")
{
	_isInit = false;
}

/**
 * @brief Destructor of my Contact class.
 * This allows me to free resources if needed.
 */
Contact::~Contact()
{

}

/**
 * @brief Initializes the contact.
 */
void	Contact::initContact()
{
	std::cout << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	_first_name = _getUserInput("1. Enter The Firstname : ");
	_last_name = _getUserInput("2. Enter The Lastname : ");
	_nickname = _getUserInput("3. Enter The Nickname : ");
	_phone_number = _getUserInput("4. Enter The Phone number : ");
	_darkest_secret = _getUserInput("5. Enter The darkest secret : ");
	std::cout << GREEN "Contact added !" RESET << std::endl;
	std::cout << std::endl;
	_isInit = true;
}

/**
 * @brief Checks if the contact is initialized.
 * @return true if the contact is initialized, false otherwise.
 */
bool	Contact::isInitContact(void) const
{
	return (_isInit);
}

/**
 * @brief Prints the contact information.
 * @param index The index of the contact.
 */
void	Contact::printContact(int index) const
{
	if (_first_name.empty() || _last_name.empty() || _nickname.empty())
		return ;
	std::cout << std::endl;
	std::cout << "Contact: " << index << std::endl;
	std::cout << "Firstname\t" << _first_name << std::endl;
	std::cout << "Lastname\t" << _last_name << std::endl;
	std::cout << "Nickname\t" << _nickname << std::endl;
	std::cout << "Phone number\t" << _phone_number << std::endl;
	std::cout << "Darkest secret\t" << _darkest_secret << std::endl;
	std::cout << std::endl;
}

/**
 * @brief Displays the contact information.
 * @param index The index of the contact.
 */
void	Contact::viewContact(int index) const
{
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << _first_name << std::flush;
	std::cout << "|" << std::setw(10) << _last_name << std::flush;
	std::cout << "|" << std::setw(10) << _nickname << std::flush;
	std::cout << "|" << std::endl;
}

/**
 * @brief Checks if the string is printable.
 * @param str The string to check.
 * @return true if the string is printable, false otherwise.
 */
static bool _isPrintable(const std::string& str)
{
	for (std::string::const_iterator i = str.begin(); i != str.end(); ++i)
	{
		if (!std::isprint(*i))
		{
			return false;
		}
	}
	return true;
}

/**
 * @brief Gets the user input. Here I prefer to use getline instead of cin. cin.good(): checks if the stream is in good state.
 * @param str The string to display.
 * @return The user input.
 */
std::string Contact::_getUserInput(std::string str) const
{
	std::string input = "";
	bool validInput = false;

	do
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty() && _isPrintable(input))
			validInput = true;
		else
		{
			if (!std::cin)
				std::freopen("/dev/tty", "r", stdin);
			std::cin.clear();
			std::cout << RED "Invalid input. Please try again" RESET << std::endl;
			validInput = false;
		}
	} while (!validInput);
	return (input);
}
