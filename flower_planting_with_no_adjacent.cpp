//
//  flower_planting_with_no_adjacent.cpp
//
//  Created by omlenka on 08/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    void colorNode(int node, unordered_map<int,vector<int>> &G,
                   vector<int> &res, int &remaining){
        if(remaining == 0){
            return;
        }
        if(res[node-1]){
            //this node is colored, now color the adjacent ones
            return;
        }
        else{
            //color this node
            vector<bool> color = {true,true,true,true};
            int this_color = 0;
            auto itr = G.find(node);
            if(itr != G.end()){
                for(int i = 0;i<itr->second.size();i++){
                    if(res[((itr->second)[i])-1]){
                        color[res[(itr->second[i])-1]-1] = false;
                    }
                }
                for(int i = 1;i<=4;i++){
                    if(color[i-1]){
                        this_color = i;
                        break;
                    }
                }
            }
            else{
                this_color = 1;
            }
            res[node-1] = this_color;
            remaining--;
        }
    }
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        unordered_map<int,vector<int>> G;
        vector<int> res(N,0);
        if(paths.empty()){
            res.assign(N,1);
            return res;
        }
        
        for(vector<int> path: paths){
            G[path[0]].push_back(path[1]);
            G[path[1]].push_back(path[0]);
        }
        
        int node = 1;
        int remaining = N;
        while(remaining){
            colorNode(node, G, res, remaining);
            node++;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> paths = {{1,2}};
    vector<int> res = S.gardenNoAdj(10000, paths);
    return 0;
}
