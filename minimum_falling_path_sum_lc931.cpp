//
//  minimum_falling_path_sum_lc931.cpp
//
//  Created by omlenka on 03/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> DP(n,vector<int>(n,INT_MAX));
        for(int j = 0;j<n;j++){
            DP[0][j] = A[0][j];
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i+1 < n && j-1 >=0){
                    DP[i+1][j-1] = min(DP[i][j] + A[i+1][j-1], DP[i+1][j-1]);
                }
                if(i+1 < n){
                    DP[i+1][j] = min(DP[i][j] + A[i+1][j], DP[i+1][j]);
                }
                if(i+1 < n && j+1 < n){
                    DP[i+1][j+1] = min(DP[i][j] + A[i+1][j+1], DP[i+1][j+1]);
                }
            }
        }
        int res = INT_MAX;
        for(int j=0;j<n;j++){
            res = min(res, DP[n-1][j]);
        }
        return res;
    }
};
