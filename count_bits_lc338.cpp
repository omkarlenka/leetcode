//
//  count_bits_lc338.cpp
//
//  Created by omlenka on 27/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> DP(num+1,0);
        
        DP[0] = 0;
        if(num == 0)
            return DP;
        DP[1] = 1;
        if(num == 1)
            return DP;
        DP[2] = 1;
        
        int base = 2;
        
        for(int i = 3;i<=num;i++){
            int diff = i-base;
            if(diff == base){
                DP[i] = DP[base];
                base = i;
            }
            else{
                DP[i] = DP[base] + DP[diff];
            }
        }
        
        return DP;
    }
};
