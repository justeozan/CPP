#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "String: " << &str << std::endl;
	std::cout << "String: " << ptr << std::endl;
	std::cout << "String: " << &ref << std::endl;

	std::cout << "String: " << str << std::endl;
	std::cout << "String: " << *ptr << std::endl;
	std::cout << "String: " << ref << std::endl;
	return (0);
}