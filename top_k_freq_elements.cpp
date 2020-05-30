//
//  top_k_freq_elements.cpp
//
//  Created by omlenka on 30/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Comparator
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return (a.second > b.second);
    }
};
class Solution {
    
public:
    unordered_map<int,int> M;
    
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        
        
        //O(n)
        for(int n: nums)
        {
            if(M.find(n) == M.end())
                M[n] = 1;
            else
                M[n]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,Comparator> Q;
        unordered_map<int, int>::iterator itr;
        
        for(itr = M.begin();itr != M.end();itr++)
        {
            if(distance(M.begin(), itr) < k)
            {
                Q.push(make_pair(itr->first, itr->second));
            }
            else
            {
                pair<int,int> t = Q.top();
                if(itr->second > t.second)
                {
                    Q.pop();
                    Q.push(make_pair(itr->first, itr->second));
                }
            }
        }
        
        vector<int> res;
        while(!Q.empty())
        {
            pair<int,int> t = Q.top();
            Q.pop();
            res.push_back(t.first);
        }
        
        
        return res;
    }
};
