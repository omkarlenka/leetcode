//
//  android_unlock_patterns.cpp
//
//  Created by omlenka on 26/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int unlock(vector<vector<int>> &v, int r, int c, int m, int n)
{
    if(v[r][c] == 0)
        return 0;
    int res = 0;
    
    if(m == 0 && n == 0)
        return 1;
    else if(m == 0 && n > 0)
    {
        res++;
        n--;
    }
    else
    {
        m--;
        n--;
    }
    
    int tmp =  v[r][c];
    
    
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            if(i == r  && j == c)
                continue;

            if(i == r && abs(j-c) == 2)
            {
                if(v[i][1] != 0)
                    continue;
            }
            else if(j == c && abs(i-r) == 2)
            {
                if(v[1][j] != 0)
                    continue;
            }
            else if(abs(i-r) == 2 && abs(j-c) == 2)
            {
                if(v[1][1]!=0)
                    continue;
            }
            v[r][c] = 0;
            res += unlock(v, i, j, m, n);
            v[r][c] = tmp;
        }
    }
    
    return res;
}

int numberOfPatterns(int m, int n)
{
    vector<vector<int>> v(3);
    int c = 0;
    for(int i = 0;i<3;i++)
    {
        vector<int> tmp = {++c,++c,++c};
        v[i] = tmp;
    }
    int res = 0;
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            res += unlock(v,i,j,m-1,n-1);
        }
    }
    return res;
}


int main()
{
    cout << numberOfPatterns(3, 3  ) << endl;
    return 0;
}
