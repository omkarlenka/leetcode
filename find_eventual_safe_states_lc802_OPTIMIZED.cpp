//
//  find_eventual_safe_states_lc802_OPTIMIZED.cpp
//
//  Created by omlenka on 16/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
    bool dfs(vector<vector<int>>& graph, int v, vector<int> &visited, set<int> &res_set){
        if(visited[v] == 1){
            return false;
        }
        if(visited[v] == 2){
            if(res_set.find(v) != res_set.end()){
                return true;
            }
            else{
                return false;
            }
        }
        
        visited[v] = 1;
        
        vector<int> edges = graph[v];
        for(auto dst:edges){
            if(!dfs(graph,dst,visited,res_set)){
                visited[v] = 2;
                return false;
            }
        }
        visited[v] = 2;
        res_set.insert(v);
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        set<int> res_set;
        vector<int> visited(n,0); //0 = white, 1 = grey, 2 = black
        
        for(int i = 0;i<n;i++){
            if(visited[i] == 0){
                if(dfs(graph, i, visited, res_set)){
                    res_set.insert(i);
                }
            }
        }
        //convert set to vector
        vector<int> res(res_set.begin(), res_set.end());
        return res;
    }
};
