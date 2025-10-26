#include "models.hpp"
#include <iostream>

CharStack::CharStack() {
    size = 0;
    capacity = size + 1;
    arr = new char[capacity];
}

CharStack::~CharStack() {
    delete[] arr;
}

void CharStack::push(char item) {
    if (size == capacity) {
        char* old_arr = arr;
        capacity = capacity * 2;
        arr = new char[capacity];
        for (size_t i = 0; i < size; ++i) { arr[i] = old_arr[i]; }
        delete[] old_arr;
    }

    arr[size] = item;
    size++;
}

char CharStack::pop() {
    if (isEmpty()) throw std::out_of_range("Stack is empty");
    char top = arr[--size];
    return top;
}

char CharStack::peek() const {
    if (isEmpty()) throw std::out_of_range("Stack is empty");
    return arr[size - 1];
}

size_t CharStack::getSize() const {
    return size;
}

bool CharStack::isEmpty() const {
    return size == 0;
}

std::string CharStack::toString() const {
    std::string str;
    for (size_t i = 0; i < size; ++i) { 
        str += arr[i];
        str += ' ';
    }
    return str;
}
