//
//  min_stack.cpp
//
//  Created by omlenka on 08/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    stack<int> aux;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(aux.empty())
        {
            s1.push(x);
            aux.push(1);
        }
        else
        {
            if(x <= s1.top())
            {
                s1.push(x);
                aux.push(1);
            }
            else
            {
                s2.push(x);
                aux.push(2);
            }
        }
    }
    
    void pop() {
        if(aux.top() == 1)
            s1.pop();
        else
            s2.pop();
        
        aux.pop();
    }
    
    int top() {
        if(aux.top() == 1)
            return s1.top();
        else
            return s2.top();
    }
    
    int getMin() {
        return s1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
