//
//  find_min_in_rotated_sorted_array.cpp
//
//  Created by omlenka on 26/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int findMinUtil(vector<int> &nums, int s, int e)
    {
        if(s == e)
            return nums[s];
        
        int m = s+(e-s)/2;
        if(m-1 >= 0 && nums[m-1]> nums[m])
            return nums[m];
        
        if(nums[m] < nums[s])
        {
            return findMinUtil(nums, s, m-1);
        }
        else if(nums[m] > nums[e])
        {
            return findMinUtil(nums, m+1, e);
        }
        
        return nums[s];
    }
public:
    int findMin(vector<int>& nums)
    {
        return findMinUtil(nums, 0 , nums.size()-1);
    }
};
