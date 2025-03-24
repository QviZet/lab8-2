#include "Header.h"

pc::pc() : name(""), clockRate(0) {};
pc::pc(std::string toName, int toCR) : name(toName), clockRate(toCR) {};
pc::~pc() {
    name = "";
    clockRate = 0;
};

void pc::print() {
    std::cout << "\nName:\t" << name << "\nClock rate:\t" << clockRate << std::endl;
};

int pc::getCR() {
    return clockRate;
};