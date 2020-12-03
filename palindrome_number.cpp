//
//  palindrome_number.cpp
//
//  Created by omlenka on 03/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    bool isPalindromUtil(string s){
        int l = 0, r = s.length()-1;
        while(l <= r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        return isPalindromUtil(num);
    }
};
