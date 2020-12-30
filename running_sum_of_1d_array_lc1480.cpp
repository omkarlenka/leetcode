//
//  running_sum_of_1d_array_lc1480.cpp
//
//  Created by omlenka on 30/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            res[i] = res[i-1] + nums[i];
        }
        return res;
    }
};
