//
//  course_schedule_lc207_OPTIMIZED.cpp
//
//  Created by omlenka on 06/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
public:
    list<int> *adj;
    vector<int> indegree;
    int V;
    Graph(int n)
    {
        V = n;
        adj =  new list<int>[V];
        indegree.resize(V, 0);
    }
    void addEdge(int src, int dst)
    {
        adj[src].push_back(dst);
        indegree[dst]++;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        if(prerequisites.empty())
            return true;
        Graph *G = new Graph(numCourses);
        
        for(int i = 0;i<prerequisites.size();i++)
        {
            G->addEdge(prerequisites[i][1], prerequisites[i][0]);
        }
        
        queue<int> Q;
        int count = 0;
        for(int i = 0;i<numCourses;i++){
            if(G->indegree[i] == 0){
                Q.push(i);
            }
        }
        
        while(!Q.empty()){
            int n = Q.front();
            Q.pop();
            count++;
            
            for(auto itr = G->adj[n].begin();itr!= G->adj[n].end();itr++){
                G->indegree[*itr]--;
                if(G->indegree[*itr] == 0){
                    Q.push(*itr);
                }
            }
        }
        
        if(count == numCourses)
            return true;
        
        return false;
    }
};
