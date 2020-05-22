//
//  longest_line_of_consecutive_one.cpp
//
//  Created by omlenka on 22/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestLine(vector<vector<int>>& M)
    {
        int  r = M.size();
        if(r == 0)
            return 0;
        int c = M[0].size();
        if(c == 0)
            return 0;
        int res = 0;
        
        // horizontal
        for(int i = 0;i<r;i++)
        {
            int res_row = 0;
            for(int j = 0;j<c;j++)
            {
                if(M[i][j])
                    res_row++;
                else
                {
                    if(res_row > res)
                        res = res_row;
                    res_row = 0;
                }
            }
            if(res_row > res)
                res = res_row;
        }
        //vertical
        for(int j = 0;j<c;j++)
        {
            int res_col = 0;
            for(int i = 0;i<r;i++)
            {
                if(M[i][j])
                    res_col++;
                else
                {
                    if(res_col > res)
                        res = res_col;
                    res_col = 0;
                }
            }
            if(res_col > res)
                res = res_col;
        }
        
        //diagonal
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                
                int res_diag = 0;
                if(((i == 0 || j == 0) || (i-1 >=0 && j-1 >= 0 && M[i-1][j-1] == 0))  && M[i][j])
                {
                    int p = i, q = j;
                    while(p< r && q < c && M[p][q])
                    {
                        res_diag++;
                        p++;
                        q++;
                    }
                    
                    if(res_diag > res)
                        res = res_diag;
                }
            }
        }
        
        //anti diagonal
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                
                int res_antidiag = 0;
                if(((i == 0 || j == c-1) || (i-1 >=0 && j+1 <= c && M[i-1][j+1] == 0))  && M[i][j])
                {
                    int p = i, q = j;
                    while(p< r && q>=0 && M[p][q])
                    {
                        res_antidiag++;
                        p++;
                        q--;
                    }
                    
                    if(res_antidiag > res)
                        res = res_antidiag;
                }
            }
        }
        return res;
    }
};
