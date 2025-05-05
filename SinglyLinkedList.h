#pragma once
#include <iostream>
#include <memory>

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    Node(T value);
};

template<typename T>
class SinglyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    size_t size;

public:
    SinglyLinkedList();
    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();
    T& at(int index);
    void insert(int index, T value);
    void remove(int index);
    bool isEmpty() const;
    size_t getSize() const;
    bool contains(const T& value) const;
    void print() const;
};
