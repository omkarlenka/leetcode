//
//  longest_increasing_subsequence.cpp
//
//  Created by omlenka on 03/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size());
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i < nums.size() ; i++)
        {
            int max_lis = 1;
            int j = i-1;
            while(j>=0)
            {
                if(nums[j] < nums[i])
                {
                    max_lis = max(max_lis, 1+dp[j]);
                }
                j--;
            }
            dp[i] = max_lis;
            if(max_lis > res)
                res = max_lis;
        }
        return res;
    }
};
