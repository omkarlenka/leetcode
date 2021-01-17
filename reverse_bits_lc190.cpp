//
//  reverse_bits_lc190.cpp
//
//  Created by omlenka on 17/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int k = 32;
        while(k--){
            if(n&1 == 1)
                res = (res | 1);
            if(k == 0)
                break;
            res = res << 1;
            n = n >> 1;
        }
        return res;
    }
};

int main() {
    uint32_t n = 10;  //1010 - 0101
    Solution S;
    cout << S.reverseBits(n) << endl;
    
    return 0;
}
