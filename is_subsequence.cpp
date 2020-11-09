//
//  is_subsequence.cpp
//
//  Created by omlenka on 09/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(char c:t){
            if(idx == s.length()){
                break;
            }
            if(s[idx] == c){
                idx++;
            }
        }
        if(idx == s.length()){
            return true;
        }
        else{
            return false;
        }
    }
};
