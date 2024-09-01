//
// Created by Dongling Mo on 2024/9/1.
//
#ifndef LIST_H
#define LIST_H
template<class T>
class List {
    void clear();
    bool isEmpty();
    bool append(const T value);
    bool insert(const int p, const T value);
    bool deleteElement(const int p);
    bool getValue(const int p, T& value);
    bool setValue(const int p, const T value);
    bool getPos(int& p, const T value);
};
#endif // LIST_H


