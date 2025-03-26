#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {}

void ScalarConverter::convert(const std::string &input) {
	ScalarConverter::isOverflow(input);
	if (ScalarConverter::isChar(input))
		return;
	ScalarConverter::toInt(input);
}

bool ScalarConverter::isChar(const std::string &input) {
	bool isChar = (input.size() == 1 && isascii(input[0]));
	if (!isChar)
		return false;
	char c = static_cast<char>(input[0]);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	return true;
}

void ScalarConverter::toInt(const std::string &input) {
	int intValue;

	if (std::stringstream(input) >> intValue)
		std::cout << "int: " << intValue << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::toFloat(const std::string &input) {
	float floatValue;

	if (std::stringstream(input) >> floatValue)
		std::cout << std::fixed << std::setprecision(1) << "float: " << floatValue << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
}

void ScalarConverter::toDouble(const std::string &input) {
	double doubleValue;

	if (std::stringstream(input) >> doubleValue)
		std::cout << std::fixed << std::setprecision(1) << "double: " << doubleValue << std::endl;
	else
	{
		std::string lowCase = ScalarConverter::strToLower(input);
		if (lowCase == "-inff" || lowCase == "-inff" || lowCase == "nanf")
			std::cout << "double: " << lowCase << std::endl;
		else if (lowCase == "-inf" || lowCase == "+inf" || lowCase == "nan")
			std::cout << "double: " << lowCase << std::endl;
		else
			std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::toChar(const std::string &input) {
	int intValue;

	if (std::stringstream(input) >> intValue && intValue >= 0 && intValue <= 127)
		if (isprint(intValue))
			std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

