#include "SinglyLinkedList.h"
#include <stdexcept>

template<typename T>
Node<T>::Node(T value) : data(value), next(nullptr) {}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), size(0) {}

template<typename T>
void SinglyLinkedList<T>::push_front(T value) {
    auto newNode = std::make_shared<Node<T>>(value);
    newNode->next = head;
    head = newNode;
    size++;
}

template<typename T>
void SinglyLinkedList<T>::push_back(T value) {
    auto newNode = std::make_shared<Node<T>>(value);
    if (!head) head = newNode;
    else {
        auto current = head;
        while (current->next) current = current->next;
        current->next = newNode;
    }
    size++;
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {
    if (!head) throw std::out_of_range("List is empty");
    head = head->next;
    size--;
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {
    if (!head) throw std::out_of_range("List is empty");
    if (!head->next) head = nullptr;
    else {
        auto current = head;
        while (current->next->next) current = current->next;
        current->next = nullptr;
    }
    size--;
}

template<typename T>
T& SinglyLinkedList<T>::at(int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    auto current = head;
    for (int i = 0; i < index; ++i) current = current->next;
    return current->data;
}

template<typename T>
void SinglyLinkedList<T>::insert(int index, T value) {
    if (index < 0 || index > size) throw std::out_of_range("Index out of range");
    if (index == 0) push_front(value);
    else {
        auto newNode = std::make_shared<Node<T>>(value);
        auto current = head;
        for (int i = 0; i < index - 1; ++i) current = current->next;
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
}

template<typename T>
void SinglyLinkedList<T>::remove(int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    if (index == 0) pop_front();
    else {
        auto current = head;
        for (int i = 0; i < index - 1; ++i) current = current->next;
        current->next = current->next->next;
        size--;
    }
}

template<typename T>
bool SinglyLinkedList<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
size_t SinglyLinkedList<T>::getSize() const {
    return size;
}

template<typename T>
bool SinglyLinkedList<T>::contains(const T& value) const {
    auto current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

template<typename T>
void SinglyLinkedList<T>::print() const {
    auto current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Explicit instantiations
template class SinglyLinkedList<int>;
template class SinglyLinkedList<std::string>;
