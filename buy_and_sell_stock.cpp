//
//  buy_and_sell_stock.cpp.cpp
//
//  Created by omlenka on 27/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int max_profit = 0;
        int max_stock = 0;
        for(int i = prices.size()-1;i>=0;i--)
        {
            if(prices[i] >  max_stock)
            {
                max_stock = prices[i];
                continue;
            }
            
            int profit = max_stock - prices[i];
            if(profit > max_profit)
                max_profit = profit;
        }
        return max_profit;
    }
};
