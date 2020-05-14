//
//  isomorphic_strings.cpp
//
//  Created by omlenka on 14/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> M;
        unordered_set<char> S;
        
        unordered_map<char, char>::iterator itr;
        
        for(int i = 0;i<s.length();i++)
        {
            itr = M.find(s[i]);
            if(itr != M.end())
            {
                if(itr->second != t[i])
                    return false;
            }
            else if(S.find(t[i]) != S.end())
            {
                return false;
            }
            else
            {
                M[s[i]] = t[i];
                S.insert(t[i]);
            }
        }
        return true;
    }
};
