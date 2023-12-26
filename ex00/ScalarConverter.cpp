#include "ScalarConverter.hpp"
#include <cmath>

static void printIfSpecial(const std::string str) {
	if (str == "-inff" || str == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		exit(0);
	}
	if (str == "+inf" || str == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		exit(0);
	}
	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit(0);
	}
}

static void printIfChar(const std::string lit) {
	if (lit.size() != 1)
		return ;
	std::cout << "char: '" << lit[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int> (lit[0]) << std::endl;
	std::cout << "float: " << static_cast<float> (lit[0]) << std::endl;
	std::cout << "double: " << static_cast<double> (lit[0]) << std::endl;
	exit(0);
}

static int countOccurrences(char target, const std::string &str) {
    int count = 0;
    for (char ch : str)
        if (ch == target)
            count++;
    return count;
}

static bool isInt(const std::string lit) {
	return (lit.find_first_not_of("0123456789") == std::string::npos);
}

static bool isFloat(const std::string lit) {
	if (lit.find_first_not_of("0123456789.f") != std::string::npos)
		return false;
	if (countOccurrences('.', lit) > 1 || countOccurrences('f', lit) > 1)
		return false;
	if (lit.find('f') != lit.size() - 1)
		return false;
	return true;
}

static bool isDouble(const std::string lit) {
	if (lit.find_first_not_of("0123456789.") != std::string::npos)
		return false;
	if (countOccurrences('.', lit) > 1)
		return false;
	return true;
}

static bool isDecimal(const std::string lit) {
	return (lit.find_first_not_of("0123456789.") == std::string::npos);
}

static void printIfInt(const std::string lit) {
	if (lit.find('.') || lit.find('f'))
		return ;
	const char* str = lit.c_str();
	int i = std::atoi(str);
	std::cout << "char: ";
	if ((i > 0 && i < 32) || i == 127)
		std::cout << "Non displayable";
	else if (i >= 32 && i < 127)
		std::cout << "'" << static_cast<char> (i) << "'";
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

static void printIfFu(const std::string lit) {
	int point = 0;
	for (int i = 0; i < lit.size(); i++) {
		if (lit[i] == '.')
			point++;
		if (point > 1)
			return ;
	}
}

static void printIfFloat(const std::string lit) {
	float f = std::atof(lit.c_str());
	std::cout << "char: " << static_cast<char>(f) << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
    float partieEntiere;
    float mantisse = std::modf(f, &partieEntiere);
	std::cout << "float: " << partieEntiere << mantisse << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void printIfDouble(const std::string lit) {
}

static void impossibleSoPrint() {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
}

static std::string getType(const std::string lit) {
	if (lit.size() == 1)
		return "char";
	if (isInt(lit))
		return "int";
	if (isFloat(lit))
		return "float";
	if (isDouble(lit))
		return "double";
	return "error";	
}

void ScalarConverter::convert(const std::string lit) {
	std::string type = getType(lit);
	std::cout << type << std::endl;
	// printIfSpecial(lit);
	// printIfFloat(lit);
	// printIfChar(lit);
	// printIfInt(lit);
	// printIfDouble(lit);
	// printIfFu(lit);
}