//
//  longest_valid_parentheses_lc32.cpp
//
//  Created by omlenka on 25/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        stack<int> stk;
        vector<int> v(len,-1);
        
        for(int i = 0;i<len;i++){
            if(s[i] == '('){
                stk.push(i);
            }
            else if(s[i] == ')'){
                if(!stk.empty()){
                    int top = stk.top();
                    stk.pop();
                    v[top] = i;
                }
            }
        }
        
        int max_len = 0, curr_len = 0;
        int i = 0;
        while(i<len){
            if(v[i] != -1){
                curr_len += (v[i]-i)+1;
                if(curr_len > max_len){
                    max_len = curr_len;
                }
                i = v[i]+1;
            }
            else{
                curr_len = 0;
                i++;
            }
        }
        return max_len;
    }
};
