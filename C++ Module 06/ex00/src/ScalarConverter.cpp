#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) { (void)src; return *this; }

/**
 * @brief Convert the input string to the corresponding scalar type.
 * @param input The input string to convert.
 */
void ScalarConverter::convert(const std::string &input) {
	ScalarConverter::isOverflow(input);
	if (ScalarConverter::isChar(input))
		return;
	ScalarConverter::isImpossible(input);
	ScalarConverter::toChar(input);
	ScalarConverter::toInt(input);
	ScalarConverter::toFloat(input);
	ScalarConverter::toDouble(input);
}

void ScalarConverter::isOverflow(const std::string &input) {
	errno = 0;
	std::strtod(input.c_str(), NULL);
	if (errno == ERANGE)
		throw overflowException();
}

/**
 * @brief Check if the input string is a valid char.
 * And print the corresponding scalar types.
 * @param input The input string to check.
 * @return true if the input string is a valid char, false otherwise.
 */
bool ScalarConverter::isChar(const std::string &input) {
	if (!(input.size() == 1 && isprint(input[0]) && !isdigit(input[0])))
		return false;
	char c = static_cast<char>(input[0]);
	if (isprint(c))
		std::cout << "char: " << GREEN << "'" << c << "'" << RESET << std::endl;
	else
		std::cout << "char: " << RED << "Non displayable" << RESET << std::endl;
	std::cout << "int: " << GREEN << static_cast<int>(c) << RESET << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << GREEN << static_cast<float>(c) << "f" << RESET << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << GREEN << static_cast<double>(c) << RESET << std::endl;
	return true;
}

void ScalarConverter::isImpossible(const std::string &input) {
	std::string lowCase = strToLower(input);
	bool found_a_point = false;

	if (lowCase == "-inf" || lowCase == "+inf" || lowCase == "nan" ||
		lowCase == "-inff"|| lowCase == "+inff" || lowCase == "nanf")
		return;
	for (size_t i = 0; i < input.size(); i++) {
		char c = input[i];

		if (!isdigit(c) && c != '.' && c != 'f' && c != '-' && c != '+')
			throw impossibleConversion();
		if ((c == 'f' && i != input.size() - 1) || ((c == '+' || c == '-') && i != 0))
			throw impossibleConversion();
		if (c == '.' && found_a_point)
			throw impossibleConversion();
		else if (c == '.')
			found_a_point = true;
	}
}

void ScalarConverter::toChar(const std::string &input) {
	int intValue;

	if (std::stringstream(input) >> intValue && intValue >= 0 && intValue <= 127)
		if (isprint(intValue))
			std::cout << "char: " << GREEN << "'" << static_cast<char>(intValue) << "'" << RESET << std::endl;
		else
			std::cout << "char: " << RED << "Non displayable" << RESET << std::endl;
	else
		std::cout << "char: " << RED << "impossible" << RESET << std::endl;
}

void ScalarConverter::toInt(const std::string &input) {
	int intValue;

	if (std::stringstream(input) >> intValue)
		std::cout << "int: " << GREEN << intValue << RESET << std::endl;
	else
		std::cout << "int: " << RED << "impossible" << RESET << std::endl;
}

void ScalarConverter::toFloat(const std::string &input) {
	float floatValue;

	if (std::stringstream(input) >> floatValue)
		std::cout << std::fixed << std::setprecision(1) << "float: " << GREEN << floatValue << "f" << RESET << std::endl;
	else
	{
		std::string lowCase = ScalarConverter::strToLower(input);
		if (lowCase == "-inff" || lowCase == "-inff" || lowCase == "nanf")
			std::cout << "float: " << GREEN << lowCase << RESET << std::endl;
		else if (lowCase == "-inf" || lowCase == "+inf" || lowCase == "nan")
			std::cout << "float: " << GREEN << lowCase << "f" << RESET << std::endl;
		else
			std::cout << "float: " << RED << "impossible" << RESET << std::endl;
	}
}

void ScalarConverter::toDouble(const std::string &input) {
	double doubleValue;

	if (std::stringstream(input) >> doubleValue)
		std::cout << std::fixed << std::setprecision(1) << "double: " << GREEN << doubleValue << RESET << std::endl;
	else
	{
		std::string lowCase = ScalarConverter::strToLower(input);
		if (lowCase == "-inff" || lowCase == "-inff" || lowCase == "nanf")
			std::cout << "double: " << GREEN << lowCase.substr(0, lowCase.size() - 1) << RESET << std::endl;
		else if (lowCase == "-inf" || lowCase == "+inf" || lowCase == "nan")
			std::cout << "double: " << GREEN << lowCase << RESET << std::endl;
		else
			std::cout << "double: " << RED << "impossible" << RESET << std::endl;
	}
}

std::string ScalarConverter::strToLower(const std::string &input) {
	std::string lowCase = input;
	for (size_t i = 0; i < lowCase.size(); i++)
		lowCase[i] = tolower(lowCase[i]);
	return lowCase;
}

const char *ScalarConverter::impossibleConversion::what() const throw() {
	return ("The input is not a valid number. The conversion is impossible.");
}

const char *ScalarConverter::overflowException::what() const throw() {
	return ("The input is out of range. The conversion is impossible.");
}


