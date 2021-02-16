//
//  rotting_oranges_lc994.cpp
//
//  Created by omlenka on 16/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        while(true){
            bool rotten  = false;
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    if(grid[i][j] == res+2){
                        if(i + 1 < m && grid[i+1][j] == 1){
                            grid[i+1][j] = grid[i][j] + 1;
                            rotten = true;
                        }
                        if(i-1 >= 0 && grid[i-1][j] == 1){
                            grid[i-1][j] = grid[i][j] + 1;
                            rotten = true;
                        }
                        
                        if(j-1 >= 0 && grid[i][j-1] == 1){
                            grid[i][j-1] = grid[i][j] + 1;
                            rotten = true;
                        }
                        if(j+1 < n && grid[i][j+1] == 1){
                            grid[i][j+1] = grid[i][j] + 1;
                            rotten = true;
                        }
                    }
                }
            }
            
            if(rotten)
                res++;
            else
                break;
        }
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return res;
    }
};
