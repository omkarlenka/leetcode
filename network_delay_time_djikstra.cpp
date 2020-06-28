//
//  network_delay_time_djikstra.cpp
//
//  Created by omlenka on 28/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph
{
public:
    int V;
    list<pair<int,int>> *adj;
    Graph(int V)
    {
        this->V = V;
        adj = new list<pair<int,int>>[V];
    }
    void addEdge(int src, int dst, int weight)
    {
        adj[src].push_back(make_pair(dst,weight));
    }
};
class MinHeap
{
    
public:
    vector<pair<int,int>> heap;
    int heapsize;
    MinHeap(vector<pair<int,int>> v)
    {
        heap = v;
        heapsize = v.size();
        buildHeap();
    }
    int parent(int i){return (i-1)/2;}
    int left(int i)
    {
        int l = 2*i+1;
        if(l < heapsize)
            return l;
        return -1;
    }
    int right(int i)
    {
        int r = 2*i+2;
        if(r < heapsize)
            return r;
        return -1;
    }
    void heapify(int i)
    {
        int smaller = i;
        int lefti = left(i);
        int righti = right(i);
        if(lefti != -1 && heap[lefti].second < heap[smaller].second)
            smaller = lefti;
        if(righti != -1 && heap[righti].second < heap[smaller].second)
            smaller = righti;
        if(i != smaller)
        {
            swap(heap[smaller],heap[i]);
            heapify(smaller);
        }
    }
    void buildHeap()
    {
        int i = parent(heapsize-1);
        while(i >= 0)
        {
            heapify(i);
            i--;
        }
    }
    bool empty() { return (heapsize == 0);}
    pair<int,int> getMin(){return heap[0];}
    void extractMin()
    {
        swap(heap[0],heap[heapsize-1]);
        heapsize--;
        heapify(0);
    }
    int getIndex(int node)
    {
        for(int i = 0;i<heapsize;i++)
        {
            if(node == heap[i].first)
                return i;
        }
        return -1;
    }
};


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        Graph* G = new Graph(N);
        vector<pair<int,int>> dist(N);
        for(int i = 0;i<times.size();i++)
        {
            G->addEdge(times[i][0]-1,times[i][1]-1,times[i][2]);
            
        }
        for(int i = 0;i<N;i++)
        {
            if(i == K-1)
                dist[i] = make_pair(i,0);
            else
                dist[i] = make_pair(i, INT_MAX);
        }
        
        MinHeap *H = new MinHeap(dist);
        int time = 0;
        while(!H->empty())
        {
            pair<int,int> minNode = H->getMin();
            int node = minNode.first;
            int distance = minNode.second;
            if(distance == INT_MAX)
                return -1;
            H->extractMin();
            
            list<pair<int,int>>::iterator itr;
            for(itr = G->adj[node].begin();itr != G->adj[node].end();itr++)
            {
                int n1 = (*itr).first;
                int d1 = (*itr).second;
                int index = H->getIndex(n1);
                H->heap[index].second = min(H->heap[index].second, distance + d1);
                
            }
            H->buildHeap();
            
            if(H->empty())
            {
                time = distance;
            }
        }
        return time;
    }
};



