//
//  reachest_customer_wealth_lc1672.cpp
//
//  Created by omlenka on 23/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        
        for(vector<int> v: accounts){
            int wealth = 0;
            for(int n:v){
                wealth += n;
            }
            if(wealth > res){
                res = wealth;
            }
        }
        return res;
    }
};
