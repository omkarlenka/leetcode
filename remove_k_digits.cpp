//
//  remove_k_digits.cpp
//
//  Created by omlenka on 17/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> S;
        S.push(num[0]);
        int i = 1;
        int len = num.length();
        while(i < len){
            char top = S.top();
            if(num[i] >= top){
                S.push(num[i]);
            }
            else{
                while(k > 0 && !S.empty()){
                    top = S.top();
                    if(num[i] < top){
                        S.pop();
                        k--;
                    }
                    else{
                        break;
                    }
                }
                S.push(num[i]);
            }
            i++;
        }
        
        while(k > 0){
            S.pop();
            k--;
        }
        
        string res;
        while(!S.empty()){
            char top = S.top();
            S.pop();
            res += string(1,top);
        }
        reverse(res.begin(), res.end());
        
        //trim leading 0
        i = 0;
        while(i< res.length() && res[i] == '0'){
            i++;
        }
        if(i == res.length()){
            return "0";
        }
        return res.substr(i, len-i);
    }
};


int main() {
    Solution S;
    cout << S.removeKdigits("112",1) << endl;
    return 0;
}
