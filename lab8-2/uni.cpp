#include "Header.h"


template<class T>
uni<T>::uni() {
    std::cout << "Constructor uni\t" << this << std::endl;
};

template<class T>
uni<T>::uni(T* p) {
    std::cout << "Constructor uni\t" << this << std::endl;
    pointer = p;
};

template<class T>
uni<T>::uni(uni&& copy) {
    if (this != &copy) {
        std::cout << "Moving operator:\n";
        std::cout << "Move from:\t" << &copy << "\tto:\t" << this << std::endl;
        pointer = copy.pointer;
        delete copy.pointer;
    }
}

template<class T>
uni<T>::~uni() {
    std::cout << "Destructor uni \t" << this << std::endl;
    if (pointer != nullptr) {
        std::cout << "with delete \t" << pointer << std::endl;
        delete pointer;
    }
};

template<class T>
T* uni<T>::get() const {
    return pointer;
};

template<class T>
T& uni<T>::operator * () {
    return *pointer;
};

template<class T>
T* uni<T>::operator -> () {
    return pointer;
};

template<class T>
uni<T>& uni<T>::operator = (uni&& copy) {
    if (this != &copy) {
        std::cout << "Moving operator:\n";
        std::cout << "Move from:\t" << &copy << "\tto:\t" << this << std::endl;
        delete pointer;
        pointer = copy.pointer;
        copy.pointer = nullptr;
    }
    return *this;
}

template<typename T, typename...Args> 
uni<T> createUni(const Args& ... args)
{
    T* newT = new T(args...);
    return uni<T>(newT);
}