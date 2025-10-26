#pragma once
#include <string>

class CharStack {
private:
    char* arr;
    size_t size;
    size_t capacity;

public:
    CharStack();
    ~CharStack();

    void push(char item);
    char pop();
    char peek() const;
    size_t getSize() const;
    bool isEmpty() const;
    std::string toString() const;
};