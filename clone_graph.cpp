//
//  clone_graph.cpp
//
//  Created by omlenka on 26/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 vector<Node*> neighbors;
 
 Node() {
 val = 0;
 neighbors = vector<Node*>();
 }
 
 Node(int _val) {
 val = _val;
 neighbors = vector<Node*>();
 }
 
 Node(int _val, vector<Node*> _neighbors) {
 val = _val;
 neighbors = _neighbors;
 }
 };
 */
class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if(node == NULL)
            return NULL;
        Node* clone = NULL;
        unordered_set<int> visited;
        unordered_map<int, Node*> M;
        queue<Node*> Q;
        Q.push(node);
        visited.insert(node->val);
        while(!Q.empty())
        {
            Node* n = Q.front();
            Q.pop();
            
            Node* clone_n;
            if(M.find(n->val) == M.end())
            {
                clone_n = new Node(n->val);
                M[clone_n->val] = clone_n;
            }
            else
                clone_n = M[n->val];
            if(clone == NULL)
                clone = clone_n;
            vector<Node*> v = n->neighbors;
            
            for(Node* n1: v)
            {
                Node* clone_n1;
                if(M.find(n1->val) == M.end())
                {
                    clone_n1 = new Node(n1->val);
                    M[clone_n1->val] = clone_n1;
                }
                else
                    clone_n1 = M[n1->val];
                
                if(visited.find(n1->val) == visited.end())
                {
                    Q.push(n1);
                    visited.insert(n1->val);
                }
                clone_n->neighbors.push_back(clone_n1);
            }
        }
        return clone;
    }
};

