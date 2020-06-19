//
//  implement_strstr.cpp
//
//  Created by omlenka on 18/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

class Solution {
    void populateLps(string s, vector<int> &lps)
    {
        int i = 1, j  = 0;
        while(i < s.length())
        {
            if(s[i] == s[j])
            {
                lps[i++] = ++j;
            }
            else
            {
                if(j == 0)
                    i++;
                else
                    j = lps[j-1];
            }
        }
    }
public:
    int strStr(string haystack, string needle)
    {
        if(needle.empty())
            return 0;
        if(needle.length() > haystack.length())
            return -1;
        
        vector<int> lps(haystack.length(),0);
        populateLps(needle, lps);
        
        int i = 0,j = 0;
        
        while(i < haystack.length())
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if(j == needle.length())
            {
                return (i - needle.length());
            }
            
            if(haystack[i] != needle[j])
            {
                if(j == 0)
                    i++;
                else
                    j= lps[j-1];
            }
        }
        return -1;
    }
};
