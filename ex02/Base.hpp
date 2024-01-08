#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

class Base {
public:
	virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

std::ostream &operator<<(std::ostream &o, const A &a) {
	(void) a;
	o << "A";
	return o;
}

std::ostream &operator<<(std::ostream &o, const B &b) {
	(void) b;
    o << "B";
    return o;
}

std::ostream &operator<<(std::ostream &o, const C &c) {
	(void) c;
    o << "C";
    return o;
}