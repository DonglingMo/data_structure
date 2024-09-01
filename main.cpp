#include <iostream>

#include "LinearList.h"
#include "Linked.h"
using namespace std;

void testArrayList();
void testLinkedList();

int main() {
    //testArrayList();
    testLinkedList();
    return 0;
}

void testArrayList() {
    // 创建一个 arrayList 实例，大小为 10
    arrayList<int> myArrayList(10);

    // 测试 append 方法
    myArrayList.append(1);
    myArrayList.append(2);
    myArrayList.append(3);

    // 测试 length 方法
    std::cout << "Length after appending: " << myArrayList.length() << std::endl;

    // 测试 getValue 方法
    int value;
    if (myArrayList.getValue(1, value)) {
        std::cout << "Value at position 1: " << value << std::endl;
    }

    // 测试 insert 方法
    myArrayList.insert(1, 99);
    std::cout << "Length after inserting: " << myArrayList.length() << std::endl;

    // 测试 getValue 方法
    if (myArrayList.getValue(1, value)) {
        std::cout << "New value at position 1: " << value << std::endl;
    }

    // 测试 deleteElement 方法
    myArrayList.deleteElement(1);
    std::cout << "Length after deletion: " << myArrayList.length() << std::endl;

    // 测试 getValue 方法
    if (myArrayList.getValue(1, value)) {
        std::cout << "Value at position 1 after deletion: " << value << std::endl;
    }

    // 测试 getPos 方法
    int pos;
    if (myArrayList.getPos(pos, 3)) {
        std::cout << "Position of value 3: " << pos << std::endl;
    }

    // 测试 clear 方法
    myArrayList.clear();
    std::cout << "Length after clearing: " << myArrayList.length() << std::endl;

    std::cout << "Empty list:" << myArrayList.isEmpty() << std::endl;
}

// Simple test function
void testLinkedList() {
    // Create a linked list
    linkedList<int> list;

    // Test appending
    std::cout << "Appending values 10, 20, 30 to the list.\n";
    list.append(10);
    list.append(20);
    list.append(30);

    // Print list length
    std::cout << "List length: " << list.length() << "\n"; // Expected: 3

    // Test getValue
    int value;
    if (list.getValue(0, value)) {
        std::cout << "Value at index 0: " << value << "\n"; // Expected: 10
    }
    if (list.getValue(1, value)) {
        std::cout << "Value at index 1: " << value << "\n"; // Expected: 20
    }
    if (list.getValue(2, value)) {
        std::cout << "Value at index 2: " << value << "\n"; // Expected: 30
    }

    // Test insert
    std::cout << "Inserting value 15 at position 1.\n";
    list.insert(1, 15);

    // Print list values after insertion
    std::cout << "List values after insertion:\n";
    for (int i = 0; i < list.length(); ++i) {
        if (list.getValue(i, value)) {
            std::cout << "Index " << i << ": " << value << "\n"; // Expected: 10, 15, 20, 30
        }
    }

    // Test deleteElement
    std::cout << "Deleting element at position 2.\n";
    list.deleteElement(2);

    // Print list values after deletion
    std::cout << "List values after deletion:\n";
    for (int i = 0; i < list.length(); ++i) {
        if (list.getValue(i, value)) {
            std::cout << "Index " << i << ": " << value << "\n"; // Expected: 10, 15, 30
        }
    }

    // Test getPos
    int position;
    if (list.getPos(position, 30)) {
        std::cout << "Value 30 found at position: " << position << "\n"; // Expected: 2
    } else {
        std::cout << "Value 30 not found.\n";
    }

    // Clean up
    list.clear();
    std::cout << "List cleared.\n";
    std::cout << "List length after clearing: " << list.length() << "\n"; // Expected: 0
}

