#pragma once
#include <iostream>
#include <memory>

template<typename T>
struct DNode {
    T data;
    std::shared_ptr<DNode<T>> next;
    std::weak_ptr<DNode<T>> prev;
    DNode(T value);
};

template<typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<DNode<T>> head, tail;
    size_t size;

public:
    DoublyLinkedList();
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
