//
//  ones_and_zeros.cpp
//
//  Created by omlenka on 11/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        unordered_map<string, pair<int,int>> M;
        
        for(string s:strs)
        {
            int zero = 0,one=0;
            for(char c:s)
            {
                if(c == '0')
                    zero++;
                else
                    one++;
            }
            M[s] = make_pair(zero,one);
        }
        int len = strs.size();
        vector<vector<vector<int>>> DP(m+1);  //DP[m+1][len+1][n+1]
        for(int i = 0;i<m+1;i++)
        {
            vector<vector<int>> v1(len+1);
            for(int j=0;j<len+1;j++)
            {
                vector<int> v2(n+1,0);
                v1[j] = v2;
            }
            DP[i] = v1;
        }
        
        for(int i = 0;i<m+1;i++)
        {
            for(int j = 0;j<n+1;j++)
            {
                for(int k = 1;k<len+1;k++)
                {
                    int exclude = DP[i][k-1][j];
                    int include = 0;
                    if(M[strs[k-1]].first <= i && M[strs[k-1]].second <= j)
                    {
                        include = 1 + DP[i-M[strs[k-1]].first][k-1][j-M[strs[k-1]].second];
                    }
                    DP[i][k][j] = max(exclude,include);
                }
            }
        }
        
        return DP[m][len][n];
    }
};

int main()
{
    Solution S;
    vector<string> strs = {"10","0","1"};
    int m = 1;
    int n = 1;
    cout << S.findMaxForm(strs, m, n) << endl;
    return 0;
}
