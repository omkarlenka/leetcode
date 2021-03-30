//
//  xor_in_an_array_lc1486.cpp
//
//  Created by omlenka on 30/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start;
        for(int i = 1;i<n;i++){
            res ^= (start + 2*i);
        }
        return res;
    }
};
