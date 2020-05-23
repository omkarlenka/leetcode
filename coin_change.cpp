//
//  coin_change.cpp
//
//  Created by omlenka on 23/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for(int coin: coins)
        {
            for(int j = coin;j<=amount;j++)
            {
                if(dp[j-coin] != INT_MAX)
                    dp[j] = min(dp[j], 1+dp[j-coin]);
            }
        }
        if(dp[amount] == INT_MAX)
            return -1;
        
        return dp[amount];
    }
};


