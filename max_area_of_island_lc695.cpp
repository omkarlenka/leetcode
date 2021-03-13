//
//  max_area_of_island_lc695.cpp
//
//  Created by omlenka on 13/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void dfs(vector<vector<int>>& grid,int m, int n, int r, int c, int &current_area){
        if(r < 0 || r >=m || c < 0 || c >= n){
            return;
        }
        
        if(grid[r][c] != 1){
            return;
        }
        
        current_area++;
        grid[r][c] = -1;
        
        vector<vector<int>> neighbors = {{1,0},{0,1},{-1,0},{0,-1}};
        for(auto neighbor:neighbors){
            int x = r+neighbor[0];
            int y = c+neighbor[1];
            dfs(grid,m,n,x,y,current_area);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int current_area = 0;
        
        int m = grid.size();
        if(m == 0){
            return max_area;
        }
        
        int n = grid[0].size();
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    dfs(grid,m,n,i,j,current_area);
                    max_area = max(max_area, current_area);
                    current_area = 0;
                }
            }
        }
        
        return max_area;
    }
};
