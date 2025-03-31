#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>		// for isascii, isprint, isdigit...
#include <sstream>		// for std::stringstream
#include <iomanip>		// for std::fixed, std::setprecision
#include <cerrno>		// for errno
#include <cstdlib>		// for std::strtod

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

		static void isOverflow(const std::string &input);
		static bool isChar(const std::string &input);
		static void isImpossible(const std::string &input);
		static void toChar(const std::string &input);
		static void toInt(const std::string &input);
		static void toFloat(const std::string &input);
		static void toDouble(const std::string &input);

		static std::string strToLower(const std::string &input);
	public:

        static void convert(const std::string &input);

        class impossibleConversion : public std::exception {
            public:
                const char *what() const throw();
        };

		class overflowException : public std::exception {
            public:
                const char *what() const throw();
        };
};

#endif  /* SCALARCONVERTER_HPP */