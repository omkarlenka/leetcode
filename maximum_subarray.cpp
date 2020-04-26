//
//  maximum_subarray.cpp
//
//  Created by omlenka on 27/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int sum = nums[0];
        int  max_sum  = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            if(sum + nums[i]  > nums[i])
                sum =  sum+nums[i];
            else
                sum =  nums[i];
            if(sum > max_sum)
                max_sum = sum;
        }
        return max_sum;
    }
};
