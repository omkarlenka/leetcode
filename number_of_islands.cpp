//
//  number_of_islands.cpp
//
//  Created by omlenka on 16/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<char>>& G, int i, int j, int r, int c)
{
    if(G[i][j] != '1')
        return;
    
    G[i][j] = '2';
    
    if(i+1 < r && G[i+1][j] == '1')
        DFS(G, i+1, j, r, c);
    if(j+1 < c  && G[i][j+1] == '1')
        DFS(G, i, j+1, r, c);
    if(i-1 >= 0 && G[i-1][j] == '1')
        DFS(G, i-1, j, r, c);
    if(j-1 >= 0 && G[i][j-1] == '1')
        DFS(G, i, j-1, r, c);
}

int numIslands(vector<vector<char>>& G)
{
    int r = int(G.size());
    int c = int(G[0].size());
    int res = 0;
    for(int i = 0;i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
            if(G[i][j] == '1')
            {
                DFS(G, i, j, r, c);
                res++;
            }
        }
    }
    return res;
}


int main()
{
    vector<vector<char>> G = {{'1','1','0','0','0'},
                              {'1','1','0','0','0'},
                              {'0','0','1','0','0'},
                              {'0','0','0','1','1'}};
    
    cout << numIslands(G);
    return 0;
}
