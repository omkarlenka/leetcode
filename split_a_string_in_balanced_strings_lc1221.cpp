//
//  split_a_string_in_balanced_strings_lc1221.cpp
//
//  Created by omlenka on 02/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int left = 0, right = 0;
        int l_count =0, r_count = 0;
        int res = 0;
        
        while(right < s.length()){
            if(s[right] == 'L'){
                l_count++;
            }
            else{
                r_count++;
            }
            
            if(l_count == r_count){
                res++;
                right++;
                left = right;
                l_count = r_count = 0;
            }
            else{
                right++;
            }
        }
        return res;
    }
};
