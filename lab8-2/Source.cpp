#include "Header.h"
#include "uni.cpp"
#include "share.cpp"

int main() {
	uni<pc> uni1 = createUni<pc>("name1", 3000);
	std::cout << "Output uni1............\n";
	uni1->print();
	uni<pc> uni2 = createUni<pc>("name2", 2000);

	std::cout << "Pointers uni1 and uni2............\n";
	std::cout << uni1.get() << std::endl;
	std::cout << uni2.get() << std::endl;
	//uni1 = uni2; //ошибка C2280: предпринята попытка ссылки на удалённую функцию
	std::cout << "Copy in uni1 from uni2............\n";
	std::cout << "Pointer uni1............\n";
	std::cout << uni1.get() << std::endl;
	std::cout << "\n\n\n";

	std::cout << uni2.get() << std::endl;
	uni2 = std::move(uni1);
	std::cout << "Pointers uni1 and uni2............\n";
	std::cout << uni1.get() << std::endl;
	std::cout << uni2.get() << "\n\n\n\n\n";

	//part2
	share<pc> share1 = createShare<pc>("name3", 6000);
	std::cout << "Output share1............\n";
	share1->print();
	share<pc> share2 = createShare<pc>("name4", 7000);
	std::cout << "Pointers share1 and share2............\n";
	std::cout << share1.get() << std::endl;
	std::cout << share2.get() << std::endl;
	std::cout << "Counters share1 and share2............\n";
	std::cout << share1.getC() << std::endl;
	std::cout << share2.getC() << std::endl;
	std::cout << "Copy in share2 from share1............\n";
	share2 = share1;
	std::cout << "Pointers share1 and share2............\n";
	std::cout << share1.get() << std::endl;
	std::cout << share2.get() << std::endl;
	std::cout << "Counters share1 and share2............\n";
	std::cout << share1.getC() << std::endl;
	std::cout << share2.getC() << std::endl;
	std::cout << "Output share1 and share2............\n";
	share1->print();
	share2->print();
	std::cout << "\n\nThe end............................\n\n\n\n";
	auto share4 = createShare<pc>("name4", 7000);
	std::cout << share1.getC() << std::endl;
	{
		share4 = share1;
		std::cout << share1.getC() << std::endl;
		auto share3 = share4;
		std::cout << share1.getC() << std::endl;
	}
	std::cout << share1.getC() << std::endl;
}