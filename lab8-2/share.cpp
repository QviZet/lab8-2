#include "Header.h"

template<class T>
share<T>::share() {
    *counter = 0;
    std::cout << "Constructor\t" << this << std::endl;
};

template<class T>
share<T>::share(T* p) {
    *counter = 1;
    pointer = p;
    std::cout << "Constructor\t" << this << std::endl;
};

template<class T>
share<T>::share(share& copy) {
    if (this != &copy) {
        pointer = copy.pointer;
        counter = copy.counter;
        *counter++;
    }
}

template<class T>
share<T>::share(share&& copy) {
    if (this != &copy) {
        std::cout << "Moving operator:\n";
        std::cout << "Move from:\t" << &copy << "\tto:\t" << this << std::endl;
        pointer = copy.pointer;
        copy.pointer = nullptr;
    }
}

template<class T>
share<T>::~share() {
    std::cout << "Destructor \t" << this << std::endl;
    if (pointer != nullptr) {
        if (*counter == 1) {
            std::cout << "with delete \t" << pointer << std::endl;
            delete pointer;
        }
        else {
            *counter -= 1;
        }
    }
};

template<class T>
int share<T>::getC() {
    return *counter;
};

template<class T>
T* share<T>::get() const {
    return pointer;
};

template<class T>
T& share<T>::operator * () {
    return *pointer;
};

template<class T>
T* share<T>::operator -> () {
    return pointer;
};

template<class T>
share<T>& share<T>::operator = (share& copy) {
    if (this != &copy) {
        if (*counter == 1) {
            delete pointer;
        }
        pointer = copy.pointer;
        counter = copy.counter;
        *counter+=1;
    }
    return *this;
}

template<class T>
share<T>& share<T>::operator = (share&& copy) {
    if (this != &copy) {
        std::cout << "Moving operator:\n";
        std::cout << "Move from:\t" << &copy << "\tto:\t" << this << std::endl;
        pointer = copy.pointer;
        delete copy.pointer;
    }
    return *this;
}

template<typename T, typename...Args>
share<T> createShare(const Args& ... args)
{
    T* newT = new T(args...);
    return share<T>(newT);
}