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
        
        vector<vector<int>> dp(nums.size());  //negative, positive
        vector<int> v = {nums[0],nums[0]};
        dp[0] = v;
        
        int max_prod = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            int n = 0, p = 0;
            int x = dp[i-1][0] * nums[i];
            int y = dp[i-1][1] * nums[i];
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
            vector<int> v = {n,p};
            dp[i] = v;
            
            if(p > max_prod)
                max_prod   = p;
        }
        return max_prod;
    }
};
