//
//  minimum_window_subsequence.cpp
//
//  Created by omlenka on 20/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T)
    {
        string res = "";
        if(T.length() > S.length())
            return res;
        int s = S.length();
        int t = T.length();
        vector<vector<int>> dp(s);
        
        for(int i = 0;i<s;i++)
        {
            vector<int> v(t,-1);
            dp[i] = v;
        }
        
        for(int i= 0;i<s;i++)
        {
            for(int j = 0;j<t;j++)
            {
                if(j == 0)
                {
                    if(S[i] == T[0])
                    {
                        dp[i][j] = i;
                    }
                    else if(i-1>=0)
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else
                {
                    if(S[i] == T[j])
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                    else if(i-1 >= 0)
                        dp[i][j]  = dp[i-1][j];
                }
            }
        }
        
        int start = -1, end = -1;
        
        for(int i = 0;i<s;i++)
        {
            if(dp[i][t-1] != -1)
            {
                if(start == -1 || (dp[i][t-1] != start && (i-dp[i][t-1]) < (end - start)))
                {
                    start = dp[i][t-1];
                    end = i;
                }
            }
        }
        
        if(start != -1)
        {
            res = S.substr(start, end-start+1);
        }
        return res;
        
    }
};
