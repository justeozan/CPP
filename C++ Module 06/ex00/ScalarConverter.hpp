#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>


class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

		static void isOverflow(const std::string &input);
		static void isChar(const std::string &input);
		static void toInt(const std::string &input);
		static void toFloat(const std::string &input);
		static void toDouble(const std::string &input);
		static void strToLower(const std::string &input);

        static void convert(const std::string &input);
};

#endif  /* SCALARCONVERTER_HPP */