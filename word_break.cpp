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
    
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> M;
        for(string word:wordDict)
        {
            M.insert(word);
        }
        
        int l = s.length();
        vector<bool> dp(l, false);
        if(M.find(string(1,s[0])) != M.end())
            dp[0] = true;
        for(int i = 1;i<l;i++)
        {
            if(M.find(s.substr(0,i+1)) != M.end())
            {
                dp[i] = true;
            }
            else
            {
                for(int j = 0;j<i;j++)
                {
                    
                    if(dp[j] && M.find(s.substr(j+1,i-j)) != M.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[l-1];
    }
};
