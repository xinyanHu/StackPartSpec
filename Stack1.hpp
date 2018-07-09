//
//  Stack1.h
//  StackPartSpec
//
//  Created by 胡欣妍 on 2018/7/4.
//  Copyright © 2018年 胡欣妍. All rights reserved.
//

#ifndef Stack1_h
#define Stack1_h

#include <iostream>
#include <vector>
#include <cassert>
template <typename T>
class Stack;

template <typename T>
std::ostream& operator <<(std::ostream& os, Stack<T> const& stack) {
    for (T elem : stack.elems) {
        os << elem << " ";
    }
    return os;
}

template <typename T>
class Stack {
    std::vector<T> elems;
    
public:
    void push(T const&);
    void pop();
    T const& top() const;
    bool empty() const {
        return elems.empty();
    }
    
    friend std::ostream& operator << <T> (std::ostream&, Stack const&);
};

template <typename T>
void Stack<T>::push(T const& elem) {
    elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T>
T const& Stack<T>::top() const {
    assert(!elems.empty());
    return elems.back();
}

#endif /* Stack1_h */
