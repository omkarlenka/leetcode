//
//  wiggle_sort.cpp
//
//  Created by omlenka on 21/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        int l = nums.size()-1;
        for(int i = 0;i<l;i++)
        {
            if(i%2 == 0 && nums[i+1] < nums[i])
                swap(nums[i], nums[i+1]);
            else if(i%2 != 0 && nums[i+1] > nums[i])
                swap(nums[i], nums[i+1]);
        }
    }
};
