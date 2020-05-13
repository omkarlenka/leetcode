//
//  split_array_argest_sum.cpp
//
//  Created by omlenka on 13/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int splitArray(vector<int>& nums, int m)
{
    vector<vector<pair<int,int>>> dp(nums.size());
    
    for(int i = 0; i<nums.size(); i++)
    {
        vector<pair<int,int>> v(m);
        dp[i] = v;
        
        for(int j = 0; j< m; j++)
        {
            if(i == 0 && j == 0)
                dp[i][j] = make_pair(nums[i], -1);
            else if(j == 0)
                dp[i][j] = make_pair(nums[i] + dp[i-1][j].first, -1);
            else if(j > i)
                dp[i][j] = make_pair(-1,-1);
            else
            {
                int val1_0 = max(dp[i-1][j-1].first, nums[i]);
                int val1_1 = nums[i];
                
                int val2_0 = -1;
                int val2_1 = -1;
                
                if(dp[i-1][j].first != -1)
                {
                    if(dp[i-1][j].second + nums[i] > dp[i-1][j].first)
                    {
                        val2_0 = dp[i-1][j].second + nums[i];
                    }
                    else
                        val2_0 = dp[i-1][j].first;
                    
                    val2_1 = dp[i-1][j].second + nums[i];
                }
                if(val2_0 == -1 || val1_0 < val2_0)
                    dp[i][j] = make_pair(val1_0, val1_1);
                else
                    dp[i][j] = make_pair(val2_0, val2_1);
            }
            
        }
        
    }
    return dp[nums.size()-1][m-1].first;
}

int main(int argc, const char * argv[])
{
    vector<int> v = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    
    cout << splitArray(v, 8) << endl;
    return 0;
}
