#include "Header.h"
#include "uni.cpp"

int main() {
	int* a;
	a = new int;
	*a = 23;
	std::cout << *a << "\n\n\n\n";
	pc* newPc;
	uni<pc> newUni = CreateObject<pc*>(newPc, "name1", 2000);
	newUni->print();
}