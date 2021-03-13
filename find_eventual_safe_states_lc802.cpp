//
//  find_eventual_safe_states_lc802.cpp
//
//  Created by omlenka on 14/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    bool dfs(unordered_map<int,vector<int>> &M, int current, unordered_map<int,bool> &visited, unordered_set<int> &local_visited){
        if(local_visited.find(current) != local_visited.end()){
            visited[current] = false;
            return false;
        }
        local_visited.insert(current);
        
        if(visited.find(current) != visited.end()){
            local_visited.erase(current);
            return visited[current];
        }
        
        vector<int> edges = M[current];
        for(auto dst:edges){
            if(dst == current){
                visited[current] = false;
                return false;
            }
            
            if(!dfs(M,dst,visited,local_visited)){
                visited[current] = false;
                return false;
            }
        }
        visited[current] = true;
        local_visited.erase(current);
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        unordered_map<int,vector<int>> M;
        
        int i = 0;
        for(auto edge: graph){
            for(auto dst: edge){
                if(M.find(i) == M.end()){
                    vector<int> v;
                    v.push_back(dst);
                    M[i] =  v;
                }
                else{
                    M[i].push_back(dst);
                }
            }
            i++;
        }
        
        unordered_map<int,bool> visited;
        
        for(int i = 0;i<n;i++){
            unordered_set<int> local_visited;
            if(dfs(M,i,visited,local_visited)){
                res.push_back(i);
            }
        }
        return res;
    }
};
