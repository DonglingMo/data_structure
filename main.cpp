#include <iostream>

#include "LinearList.h"

int main() {
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
    return 0;
}
