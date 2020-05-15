//
//  longest_substring_with_atmost_two_distinct_chars.cpp
//
//  Created by omlenka on 16/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        int k = 2;
        int res = 0;
        if(k > s.length())
            return s.length();
        
        
        unordered_map<char, int> M;
        unordered_map<char, int>::iterator itr;
        
        int l = 0, r = 0;
        // if(M.size() <= k)
        //     return M.size();
        
        while(r < s.length())
        {
            itr = M.find(s[r]);
            if(itr != M.end())
            {
                M[s[r]]++;
            }
            else
            {
                if(M.size() < k)
                {
                    M[s[r]] = 1;
                }
                else if(M.size() == k)
                {
                    while(M.size() == k)
                    {
                        if(r-l+1 > res)
                            res = r-l;
                        M[s[l]]--;
                        if(M[s[l]] == 0)
                            M.erase(s[l]);
                        
                        l++;
                    }
                    M[s[r]] = 1;
                }
            }
            r++;
        }
        
        if(M.size() <= k && res < r-l)
            res = r-l;
        
        return res;
    }
};
