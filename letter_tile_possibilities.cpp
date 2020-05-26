//
//  letter_tile_possibilities.cpp
//
//  Created by omlenka on 25/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    void getStrings(set<string> &res, unordered_map<char, int>  &M, string &curr)
    {
        unordered_map<char, int>::iterator itr;
        
        for(itr = M.begin(); itr != M.end();itr++)
        {
            if(itr->second > 0)
            {
                itr->second--;
                string curr_tmp = curr;
                curr += string(1,itr->first);
                //res.insert(string(1, itr->first));
                res.insert(curr);
                
                getStrings(res, M, curr);
                curr = curr_tmp;
                itr->second++;
            }
        }
    }
public:
    int numTilePossibilities(string tiles)
    {
        unordered_map<char, int>  M;
        for(char c: tiles)
        {
            if(M.find(c) == M.end())
                M[c] = 1;
            else
                M[c]++;
        }
        
        set<string> res;
        string curr = "";
        getStrings(res, M, curr);
        return res.size();
    }
};


