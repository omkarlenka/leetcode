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

class Anagram
{
public:
    bool isAnagram(string s1, string s2)
    {
        if(s1.length() != s2.length())
            return false;
        
        vector<int> v(26,0);
        for(char c: s1)
        {
            v[c-'a']++;
        }
        
        for(char c: s2)
        {
            v[c-'a']--;
        }
        
        for(int i:v)
        {
            if(i != 0)
                return false;
        }
        
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s)
    {
        vector<vector<string>> res;
        Anagram A;
        int l = s.size();
        vector<bool> visited(l,false);
        
        for(int i = 0;i<s.size();i++)
        {
            vector<string> v;
            if(visited[i])
                continue;
            
            v.push_back(s[i]);
            
            for(int j = i+1;j<s.size();j++)
            {
                if(!visited[i] && A.isAnagram(s[i],s[j]))
                {
                    v.push_back(s[j]);
                    visited[j] = true;
                }
            }
            visited[i] = true;
            res.push_back(v);
        }
        
        return res;
    }
};
