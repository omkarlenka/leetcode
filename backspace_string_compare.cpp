//
//  backspace_string_compare.cpp
//
//  Created by omlenka on 19/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string getNewString(string  S)
    {
        string new_S="";
        stack<char> stk;
        for(char c: S)
        {
            if(c == '#')
            {
                if(!stk.empty())
                {
                    char tmp = stk.top();
                    stk.pop();
                }
            }
            else
                stk.push(c);
        }
        while(!stk.empty())
        {
            char tmp = stk.top();
            stk.pop();
            new_S += tmp;
        }
        
        reverse(new_S.begin(), new_S.end());
        return new_S;
    }
    
    bool backspaceCompare(string S, string T)
    {
        string new_S  =  getNewString(S);
        string new_T  =  getNewString(T);
        
        return ((new_S == new_T)?true:false);
    }
};
