//
//  set_matrix_zeroes.cpp
//
//  Created by omlenka on 21/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        if(!m)
            return;
        int n = matrix[0].size();
        
        bool makeRowZero = false;
        for(int j = 0;j<n;j++)
        {
            if(matrix[0][j] == 0)
            {
                makeRowZero = true;
                break;
            }
        }
        
        for(int i = 0;i<m-1;i++)
        {
            bool tmp = false;
            for(int j = 0;j<n;j++)
            {
                if(matrix[i+1][j] == 0)
                {
                    tmp = true;
                    for(int k = i;k>=0;k--)
                        matrix[k][j] = 0;
                }
                else if(matrix[i][j] == 0)
                    matrix[i+1][j] = 0;
                
                if(makeRowZero)
                    matrix[i][j] = 0;
            }
            makeRowZero = tmp;
        }
        
        if(makeRowZero)
        {
            for(int j = 0;j<n;j++)
                matrix[m-1][j] = 0;
        }
    }
};
