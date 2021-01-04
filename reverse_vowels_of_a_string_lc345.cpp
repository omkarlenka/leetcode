//
//  reverse_vowels_of_a_string_lc345.cpp
//
//  Created by omlenka on 04/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    bool isVowel(char c){
        if(c == 'a' || c =='e' || c=='i' || c =='o' || c=='u')
            return true;
        if(c == 'A' || c =='E' || c=='I' || c =='O' || c=='U')
            return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        int l=0,r=s.length()-1;
        int left_found = false, right_found = false;
        while(l<r){
            if(!left_found && isVowel(s[l])){
                left_found = true;
            }
            else if(!isVowel(s[l])){
                l++;
            }
            
            if(!right_found && isVowel(s[r])){
                right_found = true;
            }
            else if(!isVowel(s[r])){
                r--;
            }
            
            if(left_found && right_found){
                left_found = false;
                right_found = false;
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};
