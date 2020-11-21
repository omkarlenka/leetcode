//
//  valid_palindrome.cpp
//
//  Created by omlenka on 21/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        bool res = true;
        if(s.empty()){
            return res;
        }
        int len = s.length();
        int i = 0, j = len-1;
        
        while(i<=j){
            if(!isalpha(s[i]) && !isdigit(s[i])){
                i++;
                continue;
            }
            if(!isalpha(s[j]) && !isdigit(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j])){
                res = false;
                break;
            }
            i++;
            j--;
        }
        return res;
    }
};

int main() {
    Solution S;
    string s = "A man, a plan, a canal: Panama";
    cout << S.isPalindrome(s) << endl;
    return 0;
}
