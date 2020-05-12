//
//  string_transforms_into_another_string.cpp
//
//  Created by omlenka on 12/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;
class Solution {
    
public:
    bool canConvert(string s1, string s2)
    {
        if(s1  == s2)
            return true;
        unordered_map<char, char> M;
        unordered_map<char, char>::iterator itr;
        unordered_set<char> s;
        
        int n = s1.length();
        for(int i = 0;i<n;i++)
        {
            itr = M.find(s1[i]);
            if(itr == M.end())
            {
                M[s1[i]] = s2[i];
            }
            else
            {
                if(s2[i] != itr->second)
                    return false;
            }
        }
        
        for(auto it: M)
            s.insert(it.second);
        
        return s.size() < 26;
    }
    
};
