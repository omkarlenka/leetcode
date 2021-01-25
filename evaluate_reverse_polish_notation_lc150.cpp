//
//  evaluate_reverse_polish_notation_lc150.cpp
//
//  Created by omlenka on 25/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string token:tokens){
            if(token[0] == '+' || (token[0] == '-' && token.length() == 1) || token[0] == '*' || token[0] == '/'){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                
                if(token[0] == '+'){
                    stk.push(a+b);
                }
                else if(token[0] == '-'){
                    stk.push(a-b);
                }
                else if(token[0] == '*'){
                    stk.push(a*b);
                }
                else if(token[0] == '/'){
                    stk.push(a/b);
                }
            }
            else{
                stk.push(atoi(token.c_str()));
            }
        }
        
        return stk.top();
        
    }
};

int main() {
    Solution S;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
        cout << S.evalRPN(tokens) << endl;
    return 0;
}
