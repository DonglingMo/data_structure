#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include "Node.h"

template <class T>
class linkedList : public List<T> {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

    // Helper function to get the node at position p
    Node<T>* setPos(const int p) const;

public:
    // Default constructor
    linkedList();

    // Constructor with initial size
    linkedList(int size);

    // Destructor
    ~linkedList();

    // Returns the length of the list
    int length() const;

    // Clears the list
    void clear();

    // Checks if the list is empty
    bool isEmpty() const;

    // Appends a value to the end of the list
    bool append(const T& value);

    // Inserts a value at position p
    bool insert(const int p, const T& value);

    // Deletes the element at position p
    bool deleteElement(const int p);

    // Retrieves the value at position p
    bool getValue(const int p, T& value) const;

    // Sets the value at position p
    bool setValue(const int p, const T& value);

    // Finds the position of a given value
    bool getPos(int& p, const T& value) const;
};

#include "LinkedList.tpp"

#endif // LINKEDLIST_H
