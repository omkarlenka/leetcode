//
//  buy_and_sell_stock_with_cooldown.cpp
//
//  Created by omlenka on 22/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.empty())
            return 0;
        vector<vector<int>> dp(prices.size());
        dp[0].push_back(0); //Buy
        dp[0].push_back(0);  //Sell
        dp[0].push_back(0);  //Cooldown
        dp[0].push_back(0);  //Hold
        for(int i = 1;i<prices.size();i++)
        {
            dp[i].push_back(dp[i-1][2]);
            int p1 = dp[i-1][0] + prices[i]-prices[i-1];
            int p2 = prices[i]-prices[dp[i-1][3]] + dp[dp[i-1][3]][0];
            int p = max(p1,p2);
            dp[i].push_back(max(0,p));
            dp[i].push_back(max(dp[i-1][1],dp[i-1][2]));
            if(prices[i] <= prices[dp[i-1][3]])
                dp[i].push_back(i);
            else
                dp[i].push_back(dp[i-1][3]);
        }
        
        return max(max(dp[prices.size()-1][0], dp[prices.size()-1][1]), dp[prices.size()-1][2]);
    }
};
