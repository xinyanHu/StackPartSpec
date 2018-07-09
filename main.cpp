//
//  main.cpp
//  StackPartSpec
//
//  Created by 胡欣妍 on 2018/7/4.
//  Copyright © 2018年 胡欣妍. All rights reserved.
//

#include <iostream>
#include <vector>
#include "StackSpec.hpp"
using namespace std;

template <typename T>
class Stack<T*>;

template <typename T>
std::ostream& operator <<(std::ostream& os, Stack<T*> const& stack) {
    for (int i = 0; i < stack.elems.size(); i++) {
        os << *stack.elems[i] << "";
    }
    return os;
}

template <typename T>
class Stack<T*> {
    vector<T*> elems;

public:
    void push(T*);
    T* pop();
    T* top() const;
    bool empty() const {
        return elems.empty();
    }
    
    friend std::ostream& operator << <T*> (std::ostream&, Stack const&);
};

template <typename T>
void Stack<T*>::push(T* elem) {
    elems.push_back(elem);
}

template <typename T>
T* Stack<T*>::pop() {
    assert(!elems.empty());
    T* p = elems.back();
    elems.pop_back();
    return p;
}

template <typename T>
T* Stack<T*>::top() const {
    assert(!elems.empty());
    return elems.back();
}

int main(int argc, const char * argv[]) {
    int a = 1, b = 2;
    int *p1 = &a;
    int *p2 = &b;
    
    Stack<int *> s;
    s.push(p1);
    s.push(p2);
    cout << s << endl;
    return 0;
}
