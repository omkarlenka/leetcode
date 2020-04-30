//
//  max_product_subarry.cpp
//
//  Created by omlenka on 01/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        
        int n = nums[0];
        int p = nums[0];
        int max_prod = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            int x = n * nums[i];
            int y = p * nums[i];
            if(x == y)
            {
                if(x == 0)
                {
                    n = nums[i];
                    p = nums[i];
                }
                else
                {
                    p = x;
                    n = x;
                }
            }
            else if(x  > 0)
            {
                p = x;
                n = y;
            }
            else
            {
                p = y;
                n = x;
            }
            if(nums[i] < 0)
                n = min(n, nums[i]);
            if(nums[i] > 0)
                p = max(p, nums[i]);
            
            if(p > max_prod)
                max_prod   = p;
        }
        return max_prod;
    }
};
