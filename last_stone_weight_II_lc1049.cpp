//
//  last_stone_weight_II_lc1049.cpp
//
//  Created by omlenka on 13/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        if(n == 1){
            return stones[0];
        }
        int sum = 0;
        for(int i:stones){
            sum += i;
        }
        vector<vector<bool>> DP(n+1,vector<bool>(sum+1,false));
        
        for(int i = 0;i<=n;i++){
            DP[i][0] = true;
        }
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=sum;j++){
                //exclude
                DP[i][j] = DP[i-1][j];
                //include
                if(j >= stones[i-1]){
                    DP[i][j] = DP[i][j] | (DP[i-1][j-stones[i-1]]);
                }
            }
        }
        int diff;
        for(int j = sum/2;j>=0;j--){
            if(DP[n][j]){
                diff = (sum-j)-(j);
                break;
            }
        }
        return diff;
    }
};
