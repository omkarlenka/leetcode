//
//  buy_and_sell_stock II.cpp
//
//  Created by omlenka on 21/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        int buy = -1;
        for(int i = 0;i<prices.size();i++)
        {
            if(buy == -1)
            {
                buy = prices[i];
            }
            else
            {
                if(prices[i] <= buy)
                    buy = prices[i];
                else
                {
                    if(i == prices.size()-1 || prices[i+1] < prices[i])
                    {
                        profit += prices[i] - buy;
                        buy = -1;
                    }
                }
            }
        }
        return profit;
    }
};
