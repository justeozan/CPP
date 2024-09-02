#include "../includes/Harl.hpp"

void	Harl::debug(void)
{
	std::cout << BLUE "[ DEBUG ]" RESET << std::endl;
	std::cout << BLUE " love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout << YELLOW "[ INFO ]" RESET << std::endl;
	std::cout << YELLOW "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << MAGENTA "[ WARNING ]" RESET << std::endl;
	std::cout << MAGENTA "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED "[ ERROR ]" RESET << std::endl;
	std::cout << RED "This is unacceptable, I want to speak to the manager now." RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*ptrs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = -1;
	while (++i < 4)
	{
		if (levels[i] == level)
		{
			(this->*ptrs[i])();
			break ;
		}
	}
	if (i == 4)
		std::cout << GREEN "[ Probably complaining about insignificant problems ]" RESET << std::endl;
}
