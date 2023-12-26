#include "ScalarConverter.hpp"

int err_msg(std::string str) {
	std::cerr << str << std::endl;
	return (1);
}

int main(int argc, char *argv[]) {
	if (argc != 2)
		return (err_msg("Usage: ./convert <arg>"));
	ScalarConverter::convert(argv[1]);
	return 0;
}