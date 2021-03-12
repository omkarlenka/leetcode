//
//  01_matrix_lc542.cpp
//
//  Created by omlenka on 12/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>> Q;
        
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> res(r,vector<int>(c,INT_MAX));
        
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(matrix[i][j] == 0){
                    Q.push(make_pair(i,j));
                    res[i][j] = 0;
                }
            }
        }
        
        
        while(!Q.empty()){
            auto p = Q.front();
            Q.pop();
            
            vector<vector<int>> neighbors = {{1,0},{0,1},{-1,0},{0,-1}};
            
            for(int i = 0;i<4;i++){
                int m = p.first + neighbors[i][0];
                int n = p.second + neighbors[i][1];
                if(m < 0 || m >= r || n < 0 || n >= c){
                    continue;
                }
                
                if(res[m][n] > res[p.first][p.second]+1){
                    res[m][n] = res[p.first][p.second]+1;
                    Q.push(make_pair(m,n));
                    
                }
            }
        }
        
        return res;
    }
};
