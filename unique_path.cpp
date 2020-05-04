//
//  unique_path.cpp
//
//  Created by omlenka on 03/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m+1);
        
        for(int i = 0;i < m;i++)
        {
            vector<int> v(n, 0);
            dp[i] = v;
        }
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i == 0 || j == 0)
                    dp [i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] +  dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
