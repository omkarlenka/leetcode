//
//  coin_change_2.cpp
//
//  Created by omlenka on 24/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        
        for(int coin: coins)
        {
            for(int j = coin;j<=amount;j++)
            {
                dp[j] += dp[j-coin];
            }
        }
        
        return dp[amount];
    }
};
