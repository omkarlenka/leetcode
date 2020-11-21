//
//valid_palindrome_II.cpp
//
//  Created by omlenka on 21/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    bool isPalindrome(string s, int start, int end) {
        if(start > end){
            return false;
        }
        bool res = true;
        if(s.empty()){
            return res;
        }
        int i = start, j = end;
        
        while(i<=j){
            if(s[i] != s[j]){
                res = false;
                break;
            }
            i++;
            j--;
        }
        return res;
    }
public:
    bool validPalindrome(string s) {
        if(s.empty()){
            return true;
        }
        
        int i = 0, j = s.length()-1;
        while(i <= j){
            if(s[i] != s[j]){
                return (isPalindrome(s,i+1,j)) || (isPalindrome(s,i,j-1));
            }
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    Solution S;
    cout << S.validPalindrome(s) << endl;
    return 0;
}
