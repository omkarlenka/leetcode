//
//  most_stones_removed.cpp
//
//  Created by omlenka on 25/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int root(vector<int> parent, int idx)
{
    if(parent[idx] !=  idx)
    {
        parent[idx]  = root(parent, parent[idx]);
    }
    
    return parent[idx];
}

int removeStones(vector<vector<int>>& stones)
{
    map<int, int> ROW;  //<row, index>
    map<int, int> COL;  //<col, index>
    
    map<int, int>::iterator row_itr;
    map<int, int>::iterator col_itr;
    vector<int> parent(stones.size());
    vector<int> rank(stones.size());
    for(int i = 0;i<stones.size();i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    
    for(int i = 0;i<stones.size();i++)
    {
        int r = stones[i][0];
        int c = stones[i][1];
        
        int row_parent_idx = -1;
        int col_parent_idx = -1;
        row_itr  = ROW.find(r);
        if(row_itr == ROW.end())
        {
            ROW[r]  = i;
        }
        else
        {
            row_parent_idx = row_itr->second;
        }
        
        col_itr = COL.find(c);
        if(col_itr == COL.end())
        {
            COL[c]  = i;
        }
        else
        {
            col_parent_idx = col_itr->second;
        }
        
        if(row_parent_idx != -1 && col_parent_idx != -1)
        {
            int row_root = root(parent, row_parent_idx);
            int col_root = root(parent, col_parent_idx);
            
            if(row_root == col_root)
            {
                parent[i] = row_root;  //path compression
                rank[parent[i]]++;
            }
            else
            {
                if(rank[row_root] > rank[col_root])
                {
                    parent[col_root]  = row_root;
                    parent[i] = row_root;
                    rank[row_root] += rank[col_root]+2;
                }
                else
                {
                    parent[row_root] = col_root;
                    parent[i] = col_root;
                    rank[col_root] += rank[row_root]+2;
                }
            }
        }
        else if(row_parent_idx != -1)
        {
            parent[i] = root(parent, row_parent_idx);  //path compression
            rank[parent[i]]++;
        }
        else if(col_parent_idx != -1)
        {
            parent[i] = root(parent, col_parent_idx);   //path compression
            rank[parent[i]]++;
        }
    }
    
    int moves = 0;
    for(int i = 0;i<parent.size();i++)
    {
        if(parent[i] == i)
            moves+= rank[i];
    }
    return moves;
}

int main()
{
    vector<vector<int>> v;
    
//    v = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
//    v = {{0,0},{0,2},{1,1},{2,0},{2,2}};
//    v = {{0,1},{1,0},{1,1}};
//    v = {{3,2},{0,0},{3,3},{2,1},{2,3},{2,2},{0,2}};
//    v = {{4,4},{5,5},{3,1},{1,4},{1,1},{2,3},{0,3},{2,4},{3,5}};
    v = {{6,9},{1,3},{8,0},{8,9},{5,1},{7,2},{4,0},{1,2},{4,4},{1,5},{5,3},{9,7},{3,2},{0,0},{8,2},{9,3},{0,5},{3,5},{9,9},{3,8},{4,3},{0,2}};
    cout << removeStones(v) << endl;
    
    return 0;
}
