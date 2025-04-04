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
	uni();
	uni(T* p);
	uni(uni& copy);
	uni(uni&& copy);
	~uni();
	T* get() const;
	T& operator*();
	T* operator->();
	uni<T>& operator = (uni& copy);
	uni<T>& operator = (uni&& copy);
};

template<class T>
class share
{
	T* pointer = nullptr;
	int C;
	int* counter=&C;
public:
	share();
	share(T* p);
	share(share& copy);
	share(share&& copy);
	~share();
	int getC();
	T* get() const;
	T& operator*();
	T* operator->();
	share<T>& operator = (share& copy);
	share<T>& operator = (share&& copy);
};

template<typename T, typename...Args>
uni<T> createUni(const Args& ... args);

template<typename T, typename...Args>
share<T> createShare(const Args& ... args);