//
//  course_schedule_II.cpp
//
//  Created by omlenka on 16/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj;
    Graph(int V);
    void addEdge(int s, int d);
};
Graph::Graph(int V)
{
    this->V = V;
    this->adj = new list<int>[V];
}

void Graph::addEdge(int s, int d)
{
    this->adj[s].push_back(d);
}

bool topoSort(Graph *G,  int v, vector<int> &visited, stack<int> &S, vector<int> &res)
{
    if(visited[v] == 1)  //Cycle
        return false;
    else if(visited[v] == 2)
        return true;
    
    visited[v] = 1;
    S.push(v);
    list<int>::iterator itr;
    for(itr = G->adj[v].begin();itr != G->adj[v].end();itr++)
    {
        if(!topoSort(G, *itr, visited, S, res))
            return false;
    }
    res.push_back(S.top());
    S.pop();
    visited[v] = 2;
    return true;
}

void getOrder(Graph*G, int v, vector<int> &res, vector<int> &visited)
{
    stack<int> S;
    if(!topoSort(G, v, visited, S, res))
        res.clear();
}

vector<int> findOrder(int n, vector<vector<int>>& v)
{
    Graph *G = new Graph(n);
    vector<bool> incoming(n,false);
    vector<int> res;
    if(v.size() == 0)
    {
        for(int j = 0;j<n;j++)
            res.push_back(j);
        return res;
    }
    for(int i = 0;i<v.size();i++)
    {
        if(v[i].size() > 0)
        {
            G->addEdge(v[i][0], v[i][1]);
            incoming[v[i][1]] = true;
        }
    }
    
    vector<int> startNodes;
    for(int i = 0;i<n;i++)
    {
        if(!incoming[i] && G->adj[i].size()>0)
        {
            startNodes.push_back(i);
        }
    }
    if(startNodes.size() == 0)
        return res;
    
    vector<int> visited(G->V,0); // 0:not visited,1:visited but not in res, 2: visited and in res
    for(int i= 0;i<startNodes.size();i++)
    {
        getOrder(G, startNodes[i], res, visited);
        if(res.empty())
            return res;
    }
    if(res.size() > 0)
    {
        for(int i = 0;i<n;i++)
        {
            if(!visited[i])
            {
               if(G->adj[i].size() == 0)
                   res.push_back(i);
               else
               {
                    res.clear();
                    return res;
               }
            }
        }
    }
    return res;
}

int main()
{
    //vector<vector<int>> v = {{1,0}, {2,0}, {3,1}, {3,2},{0,1}};
    vector<vector<int>> v = {{1,0} ,{2,6},{1,7},{5,1},{6,4},{7,0},{0,5}};
    
    vector<int> res = findOrder(8, v);
    return 0;
}
