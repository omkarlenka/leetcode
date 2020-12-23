//
//  basic_calculator_lc224.cpp
//
//  Created by omlenka on 23/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
    string stripSpace(string s){
        string res;
        for(char c: s){
            if(c != ' '){
                res += string(1,c);
            }
        }
        return res;
    }
    string stripBrackets(string s){
        string res = "";
        stack<bool> stk;   //true : invert, false : don't invert
        stk.push(false);
        
        for(int i = 0;i<s.length();i++){
            if(s[i] == ')'){
                stk.pop();
            }
            else{
                if(s[i] == '+'){
                    if(stk.top()){
                        res += string(1,'-');
                    }
                    else{
                        res += string(1,'+');
                    }
                    if(i+1 < s.length() && s[i+1] == '('){
                        stk.push(stk.top());
                    }
                }
                else if(s[i] == '-'){
                    if(stk.top()){
                        res += string(1,'+');
                    }
                    else{
                        res += string(1,'-');
                    }
                    if(i+1 < s.length() && s[i+1] == '('){
                        stk.push(!stk.top());
                    }
                }
                else{
                    if(i == 0 && s[i] == '('){
                        stk.push(false);
                    }
                    else if(s[i] != '('){
                        res += string(1,s[i]);
                    }
                }
            }
        }
        return res;
    }
    
    int evalExpression(string s){
        int res = 0;
        int i = 0;
        int current_num = 0;
        char operation = '+';
        while(i < s.length()){
            if(s[i] == '+' || s[i] == '-'){
                if(operation == '+'){
                    res += current_num;
                }
                else{
                    res -= current_num;
                }
                operation = s[i];
                current_num = 0;
            }
            else{
                current_num = current_num*10 + (s[i] - '0');
            }
            i++;
        }
        if(operation == '+'){
            res += current_num;
        }
        else{
            res -= current_num;
        }
        return res;
    }
public:
    int calculate(string s) {
        string r = stripBrackets(stripSpace(s));
        return evalExpression(r);
    }
};

int main() {
    Solution S;
    cout << S.calculate("1- (2- 5- (4-  (5-6)  ))   ") << endl;
    return 0;
}
