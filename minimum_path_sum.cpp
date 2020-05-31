//
//  minimum_path_sum.cpp
//
//  Created by omlenka on 31/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c  = grid[0].size();
        
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                if(i == 0 && j == 0)
                    continue;
                if(i == 0)
                    grid[i][j] +=  grid[i][j-1];
                else if(j == 0)
                    grid[i][j] += grid[i-1][j];
                else
                {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
            }
        }
        return grid[r-1][c-1];
    }
};
