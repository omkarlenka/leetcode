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
        sort(nums.begin(), nums.end());
        for(int i = 1;i<nums.size();i+=2)
        {
            if(i != nums.size()-1)
                swap(nums[i], nums[i+1]);
        }
    }
};
