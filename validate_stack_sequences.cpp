//
//  validate_stack_sequences.cpp
//
//  Created by omlenka on 30/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        int l = pushed.size();
        int i = 0, j = 0;
        stack<int> s;
        while(i < l && j < l)
        {
            if(pushed[i] == popped[j])
            {
                i++;
                j++;
            }
            else if(!s.empty() && popped[j] == s.top())
            {
                s.pop();
                j++;
            }
            else
            {
                s.push(pushed[i]);
                i++;
            }
        }
        if(i < l && j == l)
            return false;
        
        while(j < l)
        {
            if(s.empty())
                return false;
            int t = s.top();
            s.pop();
            if(t != popped[j])
                return false;
            j++;
        }
        
        return true;
    }
};
