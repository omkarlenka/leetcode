//
//  unique_binary_search_trees.cpp
//
//  Created by omlenka on 21/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n)
    {
        if(n == 0 || n == 1)
            return 1;
        vector<int> dp(n+1,0);
        
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            for(int j = 1;j<=i;j++)
            {
                int left = dp[j-1];
                int right = dp[i-j];
                dp[i] += left*right;
            }
        }
        return dp[n];
    }
};


