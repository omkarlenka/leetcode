//
//  longest_substring_with_atmost_two_distinct_chars.cpp
//
//  Created by omlenka on 16/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

class pair_comparator
{
public:
    bool operator()(const pair<int, int> l, const pair<int, int> r) const
    {
        return (l.second <= r.second);
    }
};

class Solution {
    void getFlowUtil(unordered_map<int, set<pair<int,int>, pair_comparator>> &G, int N, int K, vector<bool> &visited, vector<int> &times)
    {
        visited[K] = true;
        unordered_map<int, set<pair<int,int>, pair_comparator>>::iterator G_itr;
        set<pair<int,int>, pair_comparator>::iterator itr;
        
        G_itr = G.find(K);
        if(G_itr == G.end())
            return;
        itr = G_itr->second.begin();
        
        while(itr != G_itr->second.end())
        {
            if(!visited[itr->first] || (visited[itr->first] && times[K]+itr->second < times[itr->first]))
            {
                times[itr->first] = times[K]+itr->second;
                getFlowUtil(G, N, itr->first, visited, times);
            }
            itr++;
        }
    }
    
    int getFlowTime(unordered_map<int, set<pair<int,int>, pair_comparator>> &G, int N, int K)
    {
        vector<int> times(N+1, -1);
        vector<bool> visited(N+1, false);
        times[K] = 0;
        getFlowUtil(G, N, K, visited, times);
        
        int max_time = 0;
        
        for(int i = 1;i <= N;i++)
        {
            if(times[i] == -1)
            {
                max_time = times[i];
                break;
            }
            
            if(times[i] > max_time)
                max_time = times[i];
        }
        return max_time;
    }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        //handle error conditions
        if(N == 1)
            return 0;
        //
        
        unordered_map<int, set<pair<int,int>, pair_comparator>> G;   //src -> <dst, distance>
        
        for(int i = 0;i<times.size();i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            
            G[u].insert(make_pair(v,w));
        }
        
        return getFlowTime(G, N, K);
    }
};
