//
//  remove_outermost_parantheses.cpp
//
//  Created by omlenka on 19/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S)
    {
        string res;
        int l = S.length();
        int opened = 0;
        for(int i = 0;i<l;i++)
        {
            if(S[i] == '(')
                opened++;
            
            if(opened > 1)
            {
                res+= string(1, S[i]);
            }
            if(S[i] == ')')
                opened--;
        }
        return res;
    }
};
