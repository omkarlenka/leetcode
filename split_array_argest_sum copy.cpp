//
//  split_array_argest_sum.cpp
//
//  Created by omlenka on 13/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m)
    {
        int n = nums.size();
        vector<vector<long>> dp(n);
        
        for(int i = 0; i<n; i++)
        {
            vector<long> v(m);
            dp[i] = v;
            for(int j = 0;j<m;j++)
            {
                dp[i][j] = INT_MAX;
                if(i == 0 && j == 0)
                    dp[i][j] = nums[i];
                else if(j == 0)
                    dp[i][j] = nums[i] + dp[i-1][j];
                else
                {
                    for(int k = 0;k<i; k++)
                    {
                        dp[i][j]  = min(dp[i][j], max(dp[k][j-1], dp[i][0]-dp[k][0]));
                    }
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};

int main(int argc, const char * argv[])
{
    vector<int> v = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    
    cout << splitArray(v, 8) << endl;
    return 0;
}
