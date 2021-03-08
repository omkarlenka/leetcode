//
//  redundabnt_connection_lc684.cpp
//
//  Created by omlenka on 08/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        unordered_set<int> s;
        
        for(auto edge:edges){
            if(s.find(edge[0]) != s.end() && s.find(edge[1]) != s.end()){
                res = edge;
                // break;
            }
            s.insert(edge[0]);
            s.insert(edge[1]);
        }
        return res;
    }
};
