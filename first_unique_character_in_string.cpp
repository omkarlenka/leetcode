//
//  first_unique_character_in_string.cpp
//
//  Created by omlenka on 03/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s)
    {
        unordered_map<char,int> M;
        
        for(char c: s)
            M[c]++;
        for(int i = 0;i<s.length();i++)
        {
            if(M[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
