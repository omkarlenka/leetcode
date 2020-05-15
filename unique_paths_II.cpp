//
//  unique_paths_II.cpp
//
//  Created by omlenka on 15/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& G)
    {
        int r = G.size();
        if(r == 0)
            return 0;
        int c  = G[0].size();
        if(c == 0)
            return 0;
        
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                if(G[i][j])
                {
                    G[i][j] = -1;
                }
            }
        }
        
        
        if(G[0][0] == -1 || G[r-1][c-1])
            return 0;
        else
            G[0][0] = 1;
        
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                
                if(G[i][j] <= 0)
                    continue;
                
                if(j+1 < c && G[i][j+1] != -1)
                    G[i][j+1] += G[i][j];
                if(i+1 < r && G[i+1][j] != -1)
                    G[i+1][j] += G[i][j];
            }
        }
        return G[r-1][c-1];
    }
};
