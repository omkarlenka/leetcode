//
//  score_of_parantheses.cpp
//
//  Created by omlenka on 26/09/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int,int> M;
    void updateOpenClose(string s)
    {
        stack<char> stk;
        int len = s.length();
        for(int i = 0;i<len;i++)
        {
            if(s[i] == '(')
                stk.push(i);
            else {
                int top = stk.top();
                stk.pop();
                M[top] = i;
            }
        }
    }
    int getScore(string s, int start, int end)
    {
        int score = 0;
        while(start < end)
        {
            int open = start;
            int closed = M[start];
            if(closed == open + 1)
            {
                score++;
            }
            else
            {
                score += 2*getScore(s, open+1, closed-1);
            }
            start = closed+1;
        }
        return score;
    }
public:
    int scoreOfParentheses(string S) {
        updateOpenClose(S);
        return getScore(S, 0, S.length()-1);
    }
};
