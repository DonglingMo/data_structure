#include <iostream>
//
// Created by Dongling Mo on 2024/9/1.
//
template <class T>
bool arrayList<T>::getPos(int &p, const T value) {
    for (int i = 0; i < maxSize; ++i) {
        if (value == aList[i]) {
            p = i;
            return true;
        }
    }
    return false;
}


template<class T>
bool arrayList<T>::insert(const int p, const T value) {
    if (curLen >= maxSize) {
        std::cout << "This list is overflow" << std::endl;
        return false;
    }

    if (p < 0 || p > curLen) {
        std::cout << "Insert point is illegal" << std::endl;
        return false;
    }

    //从末尾向前移动
    for (int i = curLen; i > p; i--) {
        aList[i] = aList[i - 1];
    }
    aList[p] = value;
    curLen++;
    return true;
}

template<class T>
bool arrayList<T>::deleteElement(const int p) {
    if (curLen <= 0) {
        std::cout << "No element to delete" << std::endl;
        return false;
    }
    if (p < 0 || p > curLen - 1) {
        std::cout << "deletion is illegal" << std::endl;
        return false;
    }
    for (int i = p; i < curLen - 1; i++) {
        aList[i] = aList[i + 1];
    }
    curLen--;
    return true;
}

template<class T>
bool arrayList<T>::append(const T value) {
    if (curLen >= maxSize) {
        std::cout << "This list is overflow" << std::endl;
        return false;
    }

    aList[curLen++] = value;
    return true;
}

template <class T>
bool arrayList<T>::getValue(const int p, T& value) {
    if (p < 0 || p >= curLen) return false;
    value = aList[p];
    return true;
}

template <class T>
bool arrayList<T>::setValue(const int p, const T value) {
    if (p < 0 || p >= curLen) return false;
    aList[p] = value;
    return true;
}

template <class T>
int arrayList<T>::length() {
    return curLen;
}

template<class T>
bool arrayList<T>::isEmpty() {
    return curLen == 0;
}



