//
//  path_with_max_probability.cpp
//
//  Created by omlenka on 12/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <cfloat>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int,double>>> edge_map;
        for(int i=0;i<edges.size();i++){
            int src = edges[i][0];
            int dst = edges[i][1];
            if(edge_map.find(src) == edge_map.end()){
                vector<pair<int,double>>  v;
                v.push_back(make_pair(dst,succProb[i]));
                edge_map[src] = v;
            }
            else{
                edge_map[src].push_back(make_pair(dst,succProb[i]));
            }
            
            if(edge_map.find(dst) == edge_map.end()){
                vector<pair<int,double>>  v;
                v.push_back(make_pair(src,succProb[i]));
                edge_map[dst] = v;
            }
            else{
                edge_map[dst].push_back(make_pair(src,succProb[i]));
            }
        }
        
        priority_queue<pair<double, int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
        vector<double> probList(n, DBL_MIN);
        //        vector<bool> visited(n, false);
        
        //        visited[start] = true;
        probList[start] = 1;
        pq.push({-1,start});
        
        while(!pq.empty()){
            pair<double,int> p = pq.top();
            int node = p.second;
            double prob = -(p.first);
            pq.pop();
            
            if(probList[node] > prob){
                continue;
            }
            
            if(node == end){
                return probList[node];
            }
            
            for(int i = 0;i<edge_map[node].size();i++){
                int dst = edge_map[node][i].first;
                double prob_edge = edge_map[node][i].second;
                
                if(probList[node] * prob_edge > probList[dst]){
                    probList[dst] = prob*prob_edge;
                    pq.push({-(prob*prob_edge), dst});
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution S;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    int start = 0;
    int end = 2;
    int n = 3;
    cout << S.maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}
