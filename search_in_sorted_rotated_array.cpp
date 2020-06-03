//
//  search_in_sorted_rotated_array.cpp
//
//  Created by omlenka on 04/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int getRotationPoint(vector<int> &nums, int s, int e)
    {
        if(s > e)
            return -1;
        
        if(s == e)
            return s;
        
        int m =  s+(e-s)/2;
        
        if(m-1 >= 0 && nums[m] < nums[m-1])
            return m;
        if(m+1 <= nums.size()-1 && nums[m] > nums[m+1])
            return m+1;
        
        if(nums[m] < nums[0])
        {
            return getRotationPoint(nums, s, m-1);
        }
        else if(nums[m] > nums[nums.size()-1])
            return getRotationPoint(nums, m+1, e);
        
        return -1;
    }
    int searchUtil(vector<int> &nums, int s, int e, int target)
    {
        int m;
        
        while(s != e)
        {
            if(e-s == 1)
                break;
            if(s > e)
            {
                int part = nums.size()-s;
                int l = part+e+1;
                if(l == 2)
                    break;
                int s1 = 0;
                int e1 = l-1;
                m = s1+(e1-s1)/2;
                m = (s+m)%nums.size();
            }
            else
                m = s+(e-s)/2;
            
            if(nums[m] == target)
                return m;
            
            else if(nums[m] > target)
            {
                if(m == 0)
                {
                    e = nums.size()-1;
                }
                else
                    e = m-1;
            }
            else
            {
                if(m == nums.size()-1)
                {
                    s = 0;
                }
                else
                    s = m+1;
            }
        }
        
        if(nums[s] == target)
            return s;
        if(nums[e] == target)
            return e;
        return -1;
    }
public:
    int search(vector<int>& nums, int target)
    {
        if(nums.empty())
            return -1;
        int s = 0,e = nums.size()-1;
        int r = getRotationPoint(nums, 0, nums.size()-1);
        if(r != -1)
        {
            s = r;
            e = max(r-1,0);
        }
        return searchUtil(nums, s, e, target);
    }
};
