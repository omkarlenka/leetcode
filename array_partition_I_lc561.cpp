//
//  array_partition_I_lc561.cpp
//
//  Created by omlenka on 13/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i= 0;i<nums.size()-1;i+=2){
            res += (min(nums[i],nums[i+1]));
        }
        return res;
    }
};

