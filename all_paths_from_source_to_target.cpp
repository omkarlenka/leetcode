//
//  all_paths_from_source_to_target.cpp
//
//  Created by omlenka on 10/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    void getPathsUtil(int src, int &target, vector<vector<int>>& graph, unordered_map<int, vector<vector<int>>> &M){
        vector<vector<int>> res;
        vector<int> path;
        if(src == target){
            path.push_back(target);
            res.push_back(path);
        }
        else{
            vector<int> edges = graph[src];
            for(int edge:edges){
                getPathsUtil(edge, target, graph, M);
                if(M.find(edge) != M.end()){
                    vector<vector<int>> res_edge = M[edge];
                    for(vector<int> V:res_edge){
                        V.push_back(src);
                        res.push_back(V);
                    }
                }
            }
        }
        M[src] = res;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<vector<int>>> M;
        int src = 0,target = n-1;
        getPathsUtil(0,target,graph,M);
        for(vector<int> &V:M[0]){
            reverse(V.begin(),V.end());
        }
        return M[0];
    }
};

int main() {
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    Solution S;
    vector<vector<int>> res = S.allPathsSourceTarget(graph);
    return 0;
}
