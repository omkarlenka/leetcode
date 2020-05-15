//
//  minimum_window_substring.cpp
//
//  Created by omlenka on 15/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        int res_l=-1, res_r=-1;
        if(s.length() < t.length())
            return "";
        
        unordered_map<char,int> M;
        unordered_map<char,int>::iterator itr;
        for(char c: t)
        {
            if(M.find(c) == M.end())
                M[c] = 1;
            else
                M[c]++;
        }
        
        int l = 0, r = 0;
        int count = M.size();
        
        while(r < s.length())
        {
            itr = M.find(s[r]);
            if(M.find(s[r]) != M.end())
            {
                M[s[r]]--;
                
                if(M[s[r]] == 0)
                    count--;
            }
            
            while(count == 0)
            {
                if(res_l == -1 || r-l+1 < res_r-res_l+1)
                {
                    res_l = l;
                    res_r = r;
                }
                
                itr = M.find(s[l]);
                if(itr != M.end())
                {
                    M[s[l]]++;
                    if(M[s[l]] > 0)
                        count++;
                }
                l++;
            }
            r++;
            
        }
        if(res_l != -1)
            return s.substr(res_l, res_r-res_l+1);
        else
            return "";
    }
};
