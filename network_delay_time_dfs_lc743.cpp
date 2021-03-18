//
//  network_delay_time_dfs_lc743.cpp
//
//  Created by omlenka on 18/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class Comparator{
public:
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const{
        return (a.second < b.second);
    }
};
class Solution {
    void dfs(unordered_map<int,multiset<pair<int,int>,Comparator>> &G, int k, vector<int> &time, int curr_time){
        if(time[k] <= curr_time){
            return;
        }
        time[k] = curr_time;
        multiset<pair<int,int>,Comparator> edges = G[k];
        for(auto itr = edges.begin();itr != edges.end(); itr++){
            auto edge = *itr;
            int v = edge.first;
            int w = edge.second;
            // cout << k << " " << v << " " << w << endl;
            dfs(G,v,time,curr_time+w);
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,multiset<pair<int,int>,Comparator > > G;
        for(auto time:times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            
            if(G.find(u) == G.end()){
                G[u] = multiset<pair<int,int>,Comparator>();
            }
            
            G[u].insert(make_pair(v,w));
        }
        
        vector<int> time(n+1,INT_MAX);
        int curr_time = 0;
        dfs(G,k,time,curr_time);
        int max_time = INT_MIN;
        for(int i = 1;i<n+1;i++){
            max_time = max(max_time, time[i]);
            // cout << time[i] << " ";
        }
        
        if(max_time == INT_MAX){
            return -1;
        }
        return max_time;
    }
};

