//
//  find_first_and_last.cpp.cpp
//
//  Created by omlenka on 01/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;
class Solution {
public:
    void binSearch(vector<int> &nums, int s, int e, int target, int &left, int &right)
    {
        if(s > e)
            return;
        
        int m = (s+e)/2;
        
        if(target == nums[m])
        {
            left = min(left, m);
            right= max(right, m);
            if(m-1 >=s && nums[m-1] == target && m+1 <= e && nums[m+1] == target)
            {
                binSearch(nums, s, m-1, target, left, right);
                binSearch(nums, m+1, e, target, left, right);
            }
            else if(m-1 >=s && nums[m-1] == target)
            {
                binSearch(nums, s, m-1, target, left, right);
            }
            else if(m+1 <= e && nums[m+1] == target)
            {
                binSearch(nums, m+1, e, target, left, right);
            }
        }
        else if(target < nums[m])
        {
            binSearch(nums, s, m-1, target, left, right);
        }
        else if(target > nums[m])
        {
            binSearch(nums, m+1, e, target, left, right);
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left = INT_MAX, right = INT_MIN;
        binSearch(nums, 0, nums.size()-1, target, left, right);
        vector<int> res;
        if(left == INT_MAX && right == INT_MIN)
            res = {-1,-1};
        else
            res = {left, right};
        return res;
    }
};
