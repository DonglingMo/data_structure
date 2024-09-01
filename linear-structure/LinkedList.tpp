#ifndef LINKEDLIST_TPP
#define LINKEDLIST_TPP

#include "Linked.h"

// Default constructor
template <class T>
linkedList<T>::linkedList() : head(nullptr), tail(nullptr), size(0) {}

// Constructor with initial size
template <class T>
linkedList<T>::linkedList(int size) : head(nullptr), tail(nullptr), size(size) {}

// Destructor
template <class T>
linkedList<T>::~linkedList() {
    clear();
}

// Returns the length of the list
template <class T>
int linkedList<T>::length() const {
    return size;
}

// Clears the list
template <class T>
void linkedList<T>::clear() {
    while (!isEmpty()) {
        deleteElement(0);
    }
}

// Checks if the list is empty
template <class T>
bool linkedList<T>::isEmpty() const {
    return size == 0;
}

// Appends a value to the end of the list
template <class T>
bool linkedList<T>::append(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    ++size;
    return true;
}

// Inserts a value at position p
template <class T>
bool linkedList<T>::insert(const int p, const T& value) {
    if (p < 0 || p > size) return false;

    Node<T>* newNode = new Node<T>(value);

    if (p == 0) {
        newNode->next = head;
        head = newNode;
        if (size == 0) {
            tail = newNode;
        }
    } else if (p == size) {
        tail->next = newNode;
        tail = newNode;
    } else {
        Node<T>* prev = setPos(p - 1);
        if (!prev) {
            delete newNode;
            return false;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }

    ++size;
    return true;
}

// Deletes the element at position p
template <class T>
bool linkedList<T>::deleteElement(const int p) {
    if (p < 0 || p >= size) return false;

    Node<T>* toDelete;
    if (p == 0) {
        toDelete = head;
        head = head->next;
        if (size == 1) tail = nullptr;
    } else {
        Node<T>* prev = setPos(p - 1);
        if (!prev || !prev->next) return false;
        toDelete = prev->next;
        prev->next = toDelete->next;
        if (p == size - 1) tail = prev;
    }
    delete toDelete;
    --size;
    return true;
}

// Retrieves the value at position p
template <class T>
bool linkedList<T>::getValue(const int p, T& value) const {
    if (p < 0 || p >= size) return false;

    Node<T>* node = setPos(p);
    if (node) {
        value = node->data;
        return true;
    }
    return false;
}

// Sets the value at position p
template <class T>
bool linkedList<T>::setValue(const int p, const T& value) {
    if (p < 0 || p >= size) return false;

    Node<T>* node = setPos(p);
    if (node) {
        node->data = value;
        return true;
    }
    return false;
}

// Finds the position of a given value
template <class T>
bool linkedList<T>::getPos(int& p, const T& value) const {
    Node<T>* temp = head;
    for (int i = 0; i < size; ++i) {
        if (temp->data == value) {
            p = i;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Helper function to get the node at position p
template <class T>
Node<T>* linkedList<T>::setPos(const int p) const {
    if (p < 0 || p >= size) return nullptr;
    Node<T>* temp = head;
    for (int i = 0; i < p; ++i) {
        temp = temp->next;
    }
    return temp;
}

#endif // LINKEDLIST_TPP
