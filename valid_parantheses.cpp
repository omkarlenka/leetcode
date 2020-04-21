//
//  valid_parantheses.cpp
//
//  Created by omlenka on 21/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c: s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                stk.push(c);
            }
            else
            {
                if(!stk.empty())
                {
                    char t = stk.top();
                    stk.pop();
                    if((c == ')' && t == '(') || (c == '}' && t == '{') || (c == ']' && t == '['))
                        continue;
                    else
                        return false;
                }
                return false;
            }
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};
