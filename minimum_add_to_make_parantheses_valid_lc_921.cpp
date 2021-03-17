//
//  minimum_add_to_make_parantheses_valid_lc_921.cpp
//
//  Created by omlenka on 17/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {
        int open = 0;
        int res = 0;
        for(char c:S){
            if(c == '('){
                open++;
            }
            else{
                if(open == 0){
                    res++;
                }
                else{
                    open--;
                }
            }
        }
        res += open;
        return res;
    }
};
