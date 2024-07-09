#include "../includes/header.hpp"

/* Construceur de ma class Contact.
me permet d'initialiser des variables au prealable */
Contact::Contact() : _first_name("")
{
	_isInit = false;
}

/* Destructeur de ma class Contact.
ce qui me permettra de free au besoin */
Contact::~Contact()
{

}

/* la syntaxe "Contact::" permet d'indiquer qu'on se sert 
d'une fonction initialiser dans la class Contact.
Et sinon la fonction permet de creer un contact */
void	Contact::initContact()
{
	std::cout << "Contact Initializations...\nYou will have 5 steps.\n" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	_first_name = _getUserInput("1. Enter The Firstname : ");
	_last_name = _getUserInput("2. Enter The Lastname : ");
	_nickname = _getUserInput("3. Enter The Nickname : ");
	_phone_number = _getUserInput("4. Enter The Phone number : ");
	_darkest_secret = _getUserInput("5. Enter The darkest secret : ");
	std::cout << std::endl;
	_isInit = true;
}

bool	Contact::isInitContact(void) const
{
	return (_isInit);
}

void	Contact::printContact(int index) const
{
	if (_first_name.empty() || _last_name.empty() || _nickname.empty())
		return ;
	std::cout << std::endl;
	std::cout << "Contact: " << index << std::endl;
	std::cout << "Firstname\t" << _first_name << std::endl;
	std::cout << "Lastname\t" << _last_name << std::endl;
	std::cout << "Nickname\t" << _nickname << std::endl;
	std::cout << std::endl;
}

void	Contact::viewContact(int index) const
{
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << _first_name << std::flush;
	std::cout << "|" << std::setw(10) << _last_name << std::flush;
	std::cout << "|" << std::setw(10) << _nickname << std::flush;
	std::cout << "|" << std::endl;
}

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

/* Function that allows me to retrieve user input.
Here I prefer to use getline instead of cin.
cin.good(): checks if the stream is in good state. */
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
				std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cout << RED "Invalid input. Please try again" RESET << std::endl;
			validInput = false;
		}
	} while (!validInput);
	return (input);
}
