//
//  redundabnt_connection_lc684.cpp
//
//  Created by omlenka on 08/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int find(int n, vector<int> &parent){
        if(parent[n] == -1){
            return n;
        }
        return find(parent[n], parent);
    }
    
    void make_union(int n1, int n2, vector<int> &parent){
        int parent_n1 = find(n1,parent);
        int parent_n2 = find(n2,parent);
        parent[parent_n1] = parent_n2;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> res;
        vector<int> parent(N+1,-1);
        
        for(auto edge:edges){
            int parent1 = find(edge[0],parent);
            int parent2 = find(edge[1],parent);
            
            if(parent1 == parent2){
                res = edge;
                break;
            }
            
            make_union(edge[0], edge[1], parent);
        }
        return res;
    }
};
