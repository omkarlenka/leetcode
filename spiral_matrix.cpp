//
//  spiral_matrix.cpp
//
//  Created by omlenka on 31/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void spiralOrderUtil(vector<vector<int>>& matrix, int r, int  c, int R, int C, vector<int> &res)
    {
        if(R <= r || C <= c)
            return;
        int i = r;
        int j;
        for(j = c;j<C;j++)
        {
            res.push_back(matrix[i][j]);
        }
        j = C-1;
        for(i = r+1;i<R;i++)
        {
            res.push_back(matrix[i][j]);
        }
        i = R-1;
        if(i != r)
        {
            for(j = C-2;j>=c;j--)
            {
                res.push_back(matrix[i][j]);
            }
        }
        j = c;
        if(j != C-1)
        {
            for(i = R-2;i>r;i--)
            {
                res.push_back(matrix[i][j]);
            }
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> res;
        if(matrix.empty())
            return res;
        int R = matrix.size();
        int C = matrix[0].size();
        int max_row;
        if(R % 2)
            max_row = R/2;
        else
            max_row = R/2-1;
        for(int i = 0;i<=max_row;i++)
        {
            spiralOrderUtil(matrix, i, i, R-i, C-i, res);
        }
        return res;
    }
};

