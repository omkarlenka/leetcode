//
//  word_break.cpp
//
//  Created by omlenka on 06/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    // void printDP(vector<vector<bool>> &v)
    // {
    //     int l = v.size();
    //     for(int i = 0;i<l;i++)
    //     {
    //         for(int j = 0;j<l;j++)
    //         {
    //             cout << v[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> M;
        for(string word:wordDict)
        {
            M.insert(word);
        }
        
        int l = s.length();
        vector<vector<bool>> dp(l);
        for(int i = 0;i<l;i++)
        {
            vector<bool> v(l,false);
            dp[i] = v;
        }
        
        for(int i = l-1;i>=0;i--)
        {
            for(int j = i;j<l;j++)
            {
                string sub = s.substr(i,j-i+1);
                if(M.find(sub) != M.end())
                {
                    dp[i][j] = 1;
                }
                else
                {
                    for(int k = 1;j-k>=i;k++)
                    {
                        if(dp[i][j-k] && dp[j-k+1][j])
                        {
                            dp[i][j] = true;
                        }
                    }
                }
                
            }
        }
        // printDP(dp);
        return dp[0][l-1];
    }
};
