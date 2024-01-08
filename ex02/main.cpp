#include "Base.hpp"

// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base* generate(void) {
	std::srand(time(0));
    int nb = std::rand() % 3;
	if (nb == 0)
		return new A;
	if (nb == 1)
		return new B;
	return new C;	
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// void identify(Base& p);
void identify(Base* p) {
	std::cout << "b* pointe vers une classe de type ";
	if (dynamic_cast<A*> (p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden
void identify(Base& p) {
	std::cout << "b& pointe vers une classe de type ";
	try {
		A& a = dynamic_cast<A&> (p);
		std::cout << a << std::endl;
	} catch(std::exception& e) {}
	try {
		B& b = dynamic_cast<B&> (p);
		std::cout << b << std::endl;
	} catch(std::exception& e) {}
	try {
		C& c = dynamic_cast<C&> (p);
		std::cout << c << std::endl;
	} catch(const std::exception& e) {}
}

int main(void) {
	Base* b;

	for (int i = 0; i < 4; i++) {
		b = generate();
		identify(b);
		identify(*b);
		delete b;
		sleep(1);
		std::cout << std::endl;
	}
}