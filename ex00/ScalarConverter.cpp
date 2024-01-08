#include "ScalarConverter.hpp"
#include <cmath>

static void printIfSpecial(const std::string str) {
	if (str == "-inff" || str == "-inf" || str == "+inf" || str == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str == "-inff" || str == "+inff") {
			std::cout << "float: " << str << std::endl;
			std::cout << "double: " << str[0] << "inf" << std::endl;
		}
		else if (str == "-inf" || str == "+inf") {
			std::cout << "float: " << str << "f" << std::endl;
			std::cout << "double: " << str << std::endl;
		}
		exit(0);
	}
}

static void printImpossible() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static int countOccurrences(char target, const std::string &str) {
    int count = 0;
    for (char ch : str)
        if (ch == target)
            count++;
    return count;
}

static bool checkMinus(std::string lit) {
	if (countOccurrences('-', lit) > 1)
		return false;
	if (countOccurrences('-', lit) == 1 && lit.find('-') != 0)
		return false;
	return true;
}

static bool checkFloat(std::string lit) {
	if (countOccurrences('f', lit) > 1)
		return false;
	if (countOccurrences('f', lit) == 1 && lit.find('f') != lit.size() - 1)
		return false;
	return true;
}

static bool isChar(const std::string lit) {
	if (lit.size() != 1)
		return false;
	if (std::isdigit(lit[0]))
		return false;
	return true;
}

static bool isOther(const std::string lit) {
	if (lit.find_first_not_of("-0123456789.f") != std::string::npos)
		return false;
	if (!checkMinus(lit) || !checkFloat(lit) || countOccurrences('.', lit) > 1)
		return false;
	return true;
}

static void printChar(double i) {
	if ((i >= 0 && i < 32) || i == 127)
		std::cout << "char: Non displayable";
	else if (i >= 32 && i < 127)
		std::cout << "char: '" << static_cast<char> (i) << "'";
	else
		std::cout << "char: impossible";
	std::cout << std::endl;
}

static void printInt(double i) {
	if (i > INT32_MAX || i < INT32_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int> (i) << std::endl;
}

static void printFromChar(const std::string lit) {
	std::cout << "char: '" << lit[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int> (lit[0]) << std::endl;
	std::cout << "float: " << static_cast<float> (lit[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double> (lit[0]) << ".0" << std::endl;
}

static void printFromOther(const std::string lit) {
	double i = std::atof(lit.c_str());
	printChar(i);
	printInt(i);
	double e;
	double virgule = modf(i, &e);
	std::string precision = "";
	if (!virgule)
		precision = ".0";
	std::cout << "float: " << static_cast<float> (i) << precision << "f" << std::endl;
	std::cout << "double: " << i << precision << std::endl;
}

void ScalarConverter::convert(const std::string lit) {
	printIfSpecial(lit);
	if (isChar(lit))
		printFromChar(lit);
	else if (isOther(lit))
		printFromOther(lit);
	else
		printImpossible();
}