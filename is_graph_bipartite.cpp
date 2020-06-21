//
//  is_graph_bipartite.cpp
//
//  Created by omlenka on 21/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        unordered_set<int> S1;
        unordered_set<int> S2;
        
        for(int i = 0;i<graph.size();i++)
        {
            if(S1.find(i) == S1.end() && S2.find(i) == S2.end())
            {
                queue<int> Q;
                Q.push(i);
                S1.insert(i);
                while(!Q.empty())
                {
                    int node = Q.front();
                    Q.pop();
                    vector<int> nodes = graph[node];
                    for(int n: nodes)
                    {
                        if(S1.find(n) == S1.end() && S2.find(n) == S2.end())
                            Q.push(n);
                        if(S1.find(node) != S1.end())
                        {
                            if(S1.find(n) != S1.end())
                                return false;
                            S2.insert(n);
                        }
                        else
                        {
                            if(S2.find(n) != S2.end())
                                return false;
                            S1.insert(n);
                        }
                        
                    }
                    
                }
                
            }
        }
        return true;
    }
};


