#include "Header.h"
#include "uni.cpp"
#include "share.cpp"

int main() {
	uni<pc> uni1 = createUni<pc>("name1", 3000);
	uni1->print();
	uni<pc> uni2 = createUni<pc>("name2", 2000);
	std::cout << uni1.get() << std::endl;
	uni1 = uni2;
	std::cout << uni1.get() << std::endl;
	std::cout << "\n\n\n";

	std::cout << uni2.get() << std::endl;
	uni2 = std::move(uni1);
	std::cout << uni2.get() << std::endl;
	std::cout << uni1.get() << "\n\n\n\n\n";

	//part2
	share<pc> share1 = createShare<pc>("name3", 6000);
	share1->print();
	share<pc> share2 = createShare<pc>("name4", 7000);
	std::cout << share1.get() << std::endl;
	std::cout << share2.get() << std::endl;
	std::cout << share1.getC() << std::endl;
	std::cout << share2.getC() << std::endl;
	share2 = share1;
	std::cout << share1.get() << std::endl;
	std::cout << share2.get() << std::endl;
	std::cout << share1.getC() << std::endl;
	std::cout << share2.getC() << std::endl;
	share1->print();
	share2->print();
}