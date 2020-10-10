//
//  min_cost_climbing_stairs.cppcpp
//
//  Created by omlenka on 11/10/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = cost[1];
        int prev_prev = cost[0];
        int n = cost.size();
        
        for(int i = 2;i<n;i++)
        {
            int tmp = prev;
            prev = min(prev,prev_prev)+cost[i];
            prev_prev = tmp;
        }
        return min(prev, prev_prev);
        
    }
};
