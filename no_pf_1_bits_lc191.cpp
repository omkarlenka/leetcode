//
//  no_pf_1_bits_lc191.cpp
//
//  Created by omlenka on 24/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        int k = 32;
        while(k--){
            if(n & 0x00000001){
                res++;
            }
            n = n >> 1;
        }
        return res;
    }
};
