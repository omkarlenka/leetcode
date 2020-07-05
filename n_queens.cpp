//
//  n_queens.cpp
//
//  Created by omlenka on 05/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool isSafe(vector<string> &v, int r, int c)
    {
        //check vertical
        for(int i = 0;i<v.size();i++)
        {
            if(v[i][c] == 'Q')
                return false;
        }
        for(int i = r-1,j = c-1;i>=0 && j>=0;i--,j--)
        {
            if(v[i][j] == 'Q')
                return false;
        }
        for(int i = r+1,j = c+1;i<v.size() && j<v.size();i++,j++)
        {
            if(v[i][j] == 'Q')
                return false;
        }
        for(int i = r-1,j = c+1;i>=0 && j<v.size();i--,j++)
        {
            if(v[i][j] == 'Q')
                return false;
        }
        for(int i = r+1,j = c-1;i<v.size() && j>=0;i++,j--)
        {
            if(v[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solve(vector<string> &v, vector<vector<string>> &res, int r, int &queen)
    {
        if(r == v.size())
            return;
        
        for(int j = 0;j<v.size();j++)
        {
            if(isSafe(v,r,j))
            {
                v[r][j] = 'Q';
                queen++;
                if(queen == v.size())
                    res.push_back(v);
                solve(v,res,r+1, queen);
                v[r][j] = '.';
                queen--;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> v(n);
        vector<vector<string>> res;
        
        for(int i = 0;i<n;i++)
        {
            string s(n,'.');
            v[i] = s;
        }
        int queen = 0;
        solve(v, res, 0, queen);
        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<string>>res = S.solveNQueens(4);
    
    return 0;
}
