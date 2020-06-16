//
//  find_peak_element.cpp
//
//  Created by omlenka on 16/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int helper(vector<int> &nums, int s, int e)
    {
        if(s > e)
            return -1;
        int m;
        
        m = s+(e-s)/2;
        
        if(m-1 >= 0 && m+1 < nums.size())
        {
            if(nums[m] > nums[m-1] && nums[m] > nums[m+1])
                return m;
        }
        if(s == e)
            return -1;
        
        int l = helper(nums, s, m);
        if(l != -1)
            return l;
        return helper(nums, m+1, e);
    }
public:
    int findPeakElement(vector<int>& nums)
    {
        int i = helper(nums, 0, nums.size()-1);
        if(i == -1)
        {
            if(nums.size() == 1)
                return 0;
            if(nums.size() >= 2)
            {
                if(nums[nums.size()-1] > nums[nums.size()-2])
                    return nums.size()-1;
                if(nums[0] > nums[1])
                    return 0;
            }
        }
        return i;
    }
};
