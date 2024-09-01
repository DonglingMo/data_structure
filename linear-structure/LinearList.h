//
// Created by Dongling Mo on 2024/9/1.
//
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.h"
template <class T>
class arrayList : public List<T> {
private:
    T *aList;
    int maxSize;
    int curLen;
    int position;
public:
    arrayList(const int size) {
        maxSize = size;
        aList = new T[maxSize];
        curLen = position = 0;
    }

    ~arrayList() {
        delete [] aList;
    }

    void clear() {
        delete [] aList;
        curLen = position = 0;
        aList = new T[maxSize];
    }
    int length();
    bool append(const T value);
    bool insert(const int p, const T value);
    bool deleteElement(const int p);
    bool getValue(const int p, T& value);
    bool setValue(const int p, const T value);
    bool getPos(int& p, const T value);
    bool isEmpty();
};
#include "ArrayList.tpp"

#endif // ARRAYLIST_H


