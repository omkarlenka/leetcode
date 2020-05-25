//
//  friend_circle.cpp
//
//  Created by omlenka on 25/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int find(vector<pair<int,int>> &v, int i)
    {
        if(v[i].first != i)
            v[i].first = find(v, v[i].first);
        
        return v[i].first;
    }
    
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        int n = M.size();
        vector<pair<int,int>> v(n);
        
        for(int i = 0;i<n;i++)
        {
            v[i] = make_pair(i,1);
        }
        
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(M[i][j])
                {
                    int root_i = find(v, i);
                    int root_j = find(v,j);
                    if(root_i != root_j)
                    {
                        if(v[root_i].second < v[root_j].second)
                        {
                            v[root_i].first = root_j;
                            v[root_j].second += v[root_i].second;
                        }
                        else
                        {
                            v[root_j].first = root_i;
                            v[root_i].second += v[root_j].second;
                        }
                    }
                }
            }
        }
        
        int res = 0;
        for(int i = 0;i<n;i++)
        {
            if(v[i].first == i)
                res++;
        }
        return res;
        
    }
};


