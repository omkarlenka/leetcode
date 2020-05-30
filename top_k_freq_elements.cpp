//
//  top_k_freq_elements.cpp
//
//  Created by omlenka on 30/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int,int> M;
        
        for(int n: nums)
        {
            if(M.find(n) == M.end())
                M[n] = 1;
            else
                M[n]++;
        }
        map<int, int>::iterator itr;
        map<int,vector<int>> freq_map;
        for(itr = M.begin();itr != M.end();itr++)
        {
            if(freq_map.find(itr->second) == freq_map.end())
            {
                vector<int> v;
                v.push_back(itr->first);
                freq_map[itr->second] = v;
            }
            else
            {
                freq_map[itr->second].push_back(itr->first);
            }
        }
        
        // map<int,vector<int>>::reverse_itrerator ritr;
        auto ritr = freq_map.rbegin() ;
        vector<int> res;
        
        while(k--)
        {
            if(ritr->second.empty())
            {
                ritr++;
            }
            res.push_back(ritr->second[ritr->second.size()-1]);
            ritr->second.pop_back();
        }
        
        return res;
    }
};
