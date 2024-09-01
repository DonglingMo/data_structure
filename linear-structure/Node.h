#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
    T data;         // Data stored in the node
    Node<T>* next;  // Pointer to the next node

    // Constructor to initialize both data and next
    Node(const T& data, Node<T>* next = nullptr)
        : data(data), next(next) {}

    // Constructor to initialize next only (data is not initialized)
    Node(Node<T>* next)
        : data(T()), next(next) {}

    // Default constructor
    Node()
        : data(T()), next(nullptr) {}
};

#endif // NODE_H
