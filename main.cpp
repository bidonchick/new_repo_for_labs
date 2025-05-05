#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include <iostream>

int main() {
    try {
        SinglyLinkedList<int> sList;
        sList.push_back(10);
        sList.push_front(5);
        sList.insert(1, 7);
        sList.print();
        sList.remove(1);
        sList.print();

        DoublyLinkedList<std::string> dList;
        dList.push_back("Alice");
        dList.push_front("Bob");
        dList.insert(1, "Charlie");
        dList.print();
        dList.remove(1);
        dList.print();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
