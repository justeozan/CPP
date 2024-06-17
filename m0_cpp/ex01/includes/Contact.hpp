#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "header.hpp"

class Contact {
public:
	Contact();
	~Contact();
	void	initContact(void);
	void	viewContact(int index) const;
	void	printContact(int index) const;
	bool	isInitContact() const;
private:
	std::string	_first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	bool 		_isInit;
	std::string	_getUserInput(std::string str) const;
};

#endif