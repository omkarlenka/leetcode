//
//  longest_increasing_path.cpp
//
//  Created by omlenka on 21/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>>& v)
{
    int n = v.size();
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;
}

int DFS(vector<vector<int>> &M, vector<vector<int>>& V, int r, int c, int row, int col)
{
    int left = 1, right = 1, up = 1, down = 1;
    
    if(c-1>=0 && M[r][c-1] > M[r][c])
    {
        if(V[r][c-1])
            left = 1 + V[r][c-1];
        else
            left = 1 + DFS(M, V, r, c-1, row, col);
    }
    
    if(r-1>=0 && M[r-1][c] > M[r][c])
    {
        if(V[r-1][c])
            up = 1 + V[r-1][c];
        else
            up = 1 + DFS(M, V, r-1, c, row, col);
    }
    
    if(r+1 < row && M[r+1][c] > M[r][c])
    {
        if(V[r+1][c])
            down = 1 + V[r+1][c];
        else
            down = 1 + DFS(M, V, r+1, c, row, col);
    }
    
    if(c+1 < col && M[r][c+1] > M[r][c])
    {
        if(V[r][c+1])
            right = 1 + V[r][c+1];
        else
            right = 1 + DFS(M, V, r, c+1, row, col);
    }
    
    V[r][c] = (max(max(left,right), max(up, down)));
    return V[r][c];
}

int longestIncreasingPath(vector<vector<int>>& M)
{
    if(M.empty())
        return 0;
    
    int row = int(M.size());
    int col = int(M[0].size());
    
    vector<vector<int>> V(row);
    for(int i = 0;i<row;i++)
    {
        vector<int> tmp(col, 0);
        V[i] = tmp;
    }
    
    int len = 1, max_len = 1;
    
    for(int i =0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
        {
            if(V[i][j])
                len = V[i][j];
            else
                len = DFS(M, V, i, j, row, col);
            
            if(len > max_len)
                max_len = len;
            if(max_len == row*col)
                return max_len;
        }
        
    }
    
//    printMatrix(V);
    return max_len;
}

int main()
{
    vector<vector<int>> M  = {{3,4,5},
                              {3,2,6},
                              {2,2,1}};
    
    cout << longestIncreasingPath(M);
    return 0;
}
