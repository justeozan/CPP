#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string	ft_sed(const std::string& buffer, const std::string& oldStr, const std::string& newStr)
{
	std::string dest;
	std::size_t	pos = 0;
	std::size_t	last = 0;

	dest.reserve(buffer.length());

	while ((pos = buffer.find(oldStr, last)) != std::string::npos)
	{
		dest.append(buffer, last, (pos - last));
		dest.append(newStr);
		last = pos + oldStr.length();
	}
	dest.append(buffer.substr(last));
	return dest;
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		std::cerr << "Format expected: ./sed <filename> <old_word> <new_word >" <<std::endl;
		return 1;
	}
	std::ifstream infile(av[1]);
	if (!infile.is_open())
	{
		std::cerr << "Error: " << av[1] << ": infile can't be opened" << std::endl;
		return 1;
	}
	std::stringstream	buffer;
	buffer << infile.rdbuf();
	infile.close();
	std::string	outfileName = std::string(av[1]) + ".replace";
	std::ofstream outfile(outfileName.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: " << outfileName
		<< "outfile canno't be opened..." << std::endl;
		return 1;
	}
	outfile << ft_sed(buffer.str(), av[2], av[3]);
	outfile.close();
	return 0;
}