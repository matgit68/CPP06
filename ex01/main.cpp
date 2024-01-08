#include "Serializer.hpp"

int main(void) {
	Data original;
	uintptr_t ptr;
	Data* casted;

	original.msg = "coucou";
	ptr = Serializer::serialize(&original);
	casted = Serializer::deserialize(ptr);

	std::cout << "original :" << original.msg << std::endl;
	std::cout << ptr << std::endl;
	std::cout << "casted :" << casted->msg << std::endl;
	original.msg = "coincoin";
	std::cout << "casted :" << casted->msg << std::endl;
}