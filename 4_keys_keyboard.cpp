//
//  4_keys_keyboard.cpp
//
//  Created by omlenka on 06/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxA(int N)
    {
        if(N<=3)
            return N;
        vector<int> dp(N+1);
        
        for(int i = 0;i<=N;i++)
        {
            if(i<=5)
                dp[i]  = i;
            else
                dp[i] = max(max(dp[i-3]*2,dp[i-4]*3),dp[i-5]*4);
        }
        return dp[N];
    }
};
