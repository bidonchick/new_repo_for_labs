#include "DoublyLinkedList.h"
#include <stdexcept>

template<typename T>
DNode<T>::DNode(T value) : data(value), next(nullptr), prev() {}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
void DoublyLinkedList<T>::push_front(T value) {
    auto newNode = std::make_shared<DNode<T>>(value);
    if (!head) head = tail = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(T value) {
    auto newNode = std::make_shared<DNode<T>>(value);
    if (!tail) head = tail = newNode;
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
    if (!head) throw std::out_of_range("List is empty");
    head = head->next;
    if (head) head->prev.reset();
    else tail.reset();
    size--;
}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
    if (!tail) throw std::out_of_range("List is empty");
    tail = tail->prev.lock();
    if (tail) tail->next.reset();
    else head.reset();
    size--;
}

template<typename T>
T& DoublyLinkedList<T>::at(int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    auto current = head;
    for (int i = 0; i < index; ++i) current = current->next;
    return current->data;
}

template<typename T>
void DoublyLinkedList<T>::insert(int index, T value) {
    if (index < 0 || index > size) throw std::out_of_range("Index out of range");
    if (index == 0) push_front(value);
    else if (index == size) push_back(value);
    else {
        auto newNode = std::make_shared<DNode<T>>(value);
        auto current = head;
        for (int i = 0; i < index; ++i) current = current->next;
        auto prevNode = current->prev.lock();
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = current;
        current->prev = newNode;
        size++;
    }
}

template<typename T>
void DoublyLinkedList<T>::remove(int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    if (index == 0) pop_front();
    else if (index == size - 1) pop_back();
    else {
        auto current = head;
        for (int i = 0; i < index; ++i) current = current->next;
        auto prevNode = current->prev.lock();
        auto nextNode = current->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
size_t DoublyLinkedList<T>::getSize() const {
    return size;
}

template<typename T>
bool DoublyLinkedList<T>::contains(const T& value) const {
    auto current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const {
    auto current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Explicit instantiations
template class DoublyLinkedList<int>;
template class DoublyLinkedList<std::string>;
