//
//  3sum_closest.cpp
//
//  Created by omlenka on 16/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        int res;
        int diff = INT_MAX;
        
        for(int i = 0;i<nums.size();i++)
        {
            int l = 0, r = nums.size()-1;
            while(l < r)
            {
                if(l == i)
                {
                    l++;
                    continue;
                }
                if(r == i)
                {
                    r--;
                    continue;
                }
                int d = abs(nums[i] + nums[l] + nums[r] - target);
                if(d < diff)
                {
                    diff = d;
                    res = nums[i] + nums[l] + nums[r];
                }
                if(nums[i] + nums[l] + nums[r] < target)
                {
                    l++;
                    
                }
                else if(nums[i] + nums[l] + nums[r] > target)
                {
                    r--;
                }
                else
                    return target;
            }
            
        }
        return res;
    }
};
