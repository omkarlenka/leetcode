//
//  course_schedule.cpp
//
//  Created by omlenka on 25/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
public:
    list<int>  *adj;
    vector<bool> incoming;
    int V;
    Graph(int n)
    {
        V = n;
        adj =  new list<int>[V];
        incoming.resize(V, false);
    }
    void addEdge(int src, int dst)
    {
        adj[src].push_back(dst);
        incoming[dst] = true;
    }
};

class Solution {
    bool _canFinishUtil(Graph *G, int v, vector<bool> &visited, vector<bool> &local_visited, stack<int>  &S)
    {
        S.push(v);
        local_visited[v]  = true;
        list<int>::iterator itr;
        for(itr = G->adj[v].begin();itr !=  G->adj[v].end();itr++)
        {
            if(visited[*itr])
                continue;
            
            if(local_visited[*itr])
                return false;
            bool res = _canFinishUtil(G,*itr, visited, local_visited, S);
            if(!res)
                return false;
        }
        S.pop();
        visited[v]  = true;
        return true;
    }
    
    bool _canFinish(Graph *G, int v, vector<bool> &visited)
    {
        stack<int> S;
        vector<bool> local_visited(G->V, false);  //  this is to detect  cycle
        return _canFinishUtil(G, v, visited,local_visited, S);
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        if(prerequisites.empty())
            return true;
        Graph *G = new Graph(numCourses);
        
        for(int i = 0;i<prerequisites.size();i++)
        {
            G->addEdge(prerequisites[i][0], prerequisites[i][1]);
        }
        
        vector<bool> visited(numCourses, false);
        
        for(int i = 0;i<numCourses;i++)
        {
            if(!(G->incoming[i]))
            {
                if(_canFinish(G, i, visited)  == false)
                    return false;
            }
        }
        
        for(int i = 0;i<numCourses;i++)
        {
            if(visited[i] == false)
                return false;
        }
        
        return true;
    }
};


