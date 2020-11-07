//
//  min_swaps_to_make_strings_equal.cpp
//
//  Created by omlenka on 07/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x2y = 0, y2x = 0;
        for(int i = 0;i<s1.length();i++){
            if(s1[i] == 'x' && s2[i] == 'y'){
                x2y++;
            }
            else if(s1[i] == 'y' && s2[i] == 'x'){
                y2x++;
            }
        }
        if((x2y + y2x) & 1)
            return -1;
        int res = 0;
        if(x2y > 1)
            res += (x2y/2);
        if(y2x > 1)
            res += (y2x/2);
        
        if(x2y & 1)
            res += 2;
        return res;
    }
};
