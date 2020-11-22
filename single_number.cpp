//
//  single_number.cpp
//
//  Created by omlenka on 21/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1;i<nums.size();i++){
            res ^= nums[i];
        }
        return res;
    }
};
