#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

class pc {
	std::string name;
	int clockRate;
public:
	pc();
	pc(std::string toName, int toCR);
	~pc();
	void print();
	int getCR();
};

template<class T>
class uni
{
	T* pointer = nullptr;
	bool flag = true;
public:
	uni(T* p);
	uni(uni& copy);
	uni(uni&& copy);
	~uni();
	T* get() const;
	T& operator*();
	T* operator->();
	T& operator = (uni& copy);
};

template<typename U, typename T, typename...Args>
U CreateObject(T* newT, const Args& ... args);