
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>

class HumanA
{
	public:
		void	attack(std::string const &target, std::string weapon_type);
	private:
		std::string _Name;
		std::string _Weapon;
};

#endif