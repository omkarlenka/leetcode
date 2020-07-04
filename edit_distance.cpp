//
//  edit_distance.cpp
//
//  Created by omlenka on 04/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int l1 = word1.length();
        int l2 = word2.length();
        if(l1 == 0)
            return l2;
        
        vector<vector<int>> dp(l1);
        
        for(int i = 0;i<l1;i++)
        {
            vector<int> v(l2+1,0);
            dp[i] = v;
        }
        
        for(int i = 0;i<l1;i++)
        {
            for(int j = 0;j<l2+1;j++)
            {
                if(j == 0)
                {
                    dp[i][j] = i+1;
                }
                else if(i == 0 && j == 1)
                {
                    if(word1[i] == word2[j-1])
                        dp[i][j] = 0;
                    else
                        dp[i][j] = 1;
                }
                else if(i == 0 && j > 1)
                {
                    if(word1[i] == word2[j-1] && dp[i][j-1] == j-1)
                        dp[i][j] = dp[i][j-1];
                    else
                        dp[i][j] = dp[i][j-1]+1;
                }
                else
                {
                    int D = dp[i-1][j];
                    int R = dp[i-1][j-1];
                    int I = dp[i][j-1];
                    
                    if(word1[i] == word2[j-1])
                        dp[i][j] = min(R,min(D+1,I+1));
                    else
                        dp[i][j] = min(R+1,min(D+1,I+1));
                }
                
                
            }
        }
        
        return dp[l1-1][l2];
    }
    
};
