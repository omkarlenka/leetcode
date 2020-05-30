//
//  move_zeros.cpp
//
//  Created by omlenka on 30/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int l = 0;
        int i = 0;
        while(i < nums.size() && nums[i])
        {
            i++;
        }
        l = i;
        i++;
        
        while(i < nums.size())
        {
            if(nums[i] != 0)
            {
                swap(nums[i],nums[l]);
                l++;
            }
            i++;
        }
    }
};
