//
//  StackSpec.h
//  StackPartSpec
//
//  Created by 胡欣妍 on 2018/7/4.
//  Copyright © 2018年 胡欣妍. All rights reserved.
//

#ifndef StackSpec_h
#define StackSpec_h
#include <string>
#include <deque>
#include "Stack1.hpp"

template <>
class Stack<std::string> {
    std::deque<std::string> elems;
    
public:
    void push(std::string const&);
    void pop();
    std::string const& top() const;
    bool empty() const {
        return elems.empty();
    }
    
    friend std::ostream& operator << <std::string> (std::ostream&, Stack const&);
};

void Stack<std::string>::push(std::string const& elem) {
    elems.push_back(elem);
}

void Stack<std::string>::pop() {
    assert(!elems.empty());
    elems.pop_back();
}

std::string const& Stack<std::string>::top() const {
    assert(!elems.empty());
    return elems.back();
}

#endif /* StackSpec_h */
