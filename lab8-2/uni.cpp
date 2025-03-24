#include "Header.h"

template<class T>
uni<T>::uni(T* p) {
    pointer = p;
};

template<class T>
uni<T>::uni(uni& copy) {
    std::cout << "Copy unavailable" << std::endl;
}

template<class T>
uni<T>::uni(uni&& copy) {
    std::cout << "Перемещение из:\t" << &copy << "\tв:\t" << this << std::endl;
    pointer = copy.pointer;
    copy.flag = false;
    delete copy;
}

template<class T>
uni<T>::~uni() {
    if (flag == true) delete pointer;
    pointer = nullptr;
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
T& uni<T>::operator = (uni& copy) {
    if (this != &copy) {
        std::cout << "Copy unavailable" << std::endl;
    }
    return this;
}

template<typename U,typename T, typename...Args>
U CreateObject(T& newT, const Args& ... args)
{
    newT = new T(args...);
    U newU(newT);
    return newU;
}