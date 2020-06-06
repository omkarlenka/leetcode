//
//  group_anagrams.cpp
//
//  Created by omlenka on 07/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str)
    {
        vector<vector<string>> res;
        int i = -1;
        vector<string> v(str);
        for(int j = 0;j<v.size();j++)
        {
            sort(v[j].begin(), v[j].end());
        }
        
        unordered_map<string, int> M;
        for(int j = 0;j<v.size();j++)
        {
            if(M.find(v[j]) == M.end())
            {
                i++;
                M[v[j]] = i;
                vector<string> p;
                p.push_back(str[j]);
                res.push_back(p);
            }
            else
            {
                res[M[v[j]]].push_back(str[j]);
            }
        }
        
        return res;
    }
};
