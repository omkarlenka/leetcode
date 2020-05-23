//
//  mock_find_and _replace_in_string.cpp
//
//  Created by omlenka on 23/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        map<int, pair<string, string>> M;
        string res;
        
        for(int i = 0;i<indexes.size();i++)
        {
            M[indexes[i]] = make_pair(sources[i], targets[i]);
        }
        
        int i = 0;
        map<int, pair<string, string>>::iterator  itr = M.begin();
        while(i< S.length() && itr != M.end())
        {
            if(i < itr->first)
            {
                res+= string(1,S[i]);
                i++;
            }
            else if(i == itr->first)
            {
                string source = itr->second.first;
                string sub = S.substr(i, source.length());
                if(sub == source)
                {
                    res += itr->second.second;
                    i += source.length();
                    itr = next(itr,1);
                }
                else
                {
                    res += sub;
                    i += sub.length();
                    itr = next(itr,1);
                }
            }
        }
        
        if(i < S.length())
            res +=  S.substr(i, S.length()-i+1);
        return res;
    }
};
