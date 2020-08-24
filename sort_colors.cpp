//
//  sort_colors.cpp
//
//  Created by omlenka on 25/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int n = nums.size();
        int zi = -1,ti = n;
        int i = 0;
        while(i<n)
        {
            if(i > zi && nums[i] == 0)
            {
                swap(nums[i], nums[++zi]);
            }
            else if(nums[i] == 2)
            {
                if(i >= ti)
                    break;
                
                swap(nums[i], nums[--ti]);
            }
            else
                i++;
        }
    }
};

int main()
{
    Solution S;
    vector<int> nums = {0,0,0,0,1,1,0,0,2,1,1,1,2,2,2,2,2,1};
    S.sortColors(nums);
    return 0;
}
