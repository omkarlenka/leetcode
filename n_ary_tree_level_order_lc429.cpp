//
//  n_ary_tree_level_order_lc429.cpp
//
//  Created by omlenka on 22/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 vector<Node*> children;
 
 Node() {}
 
 Node(int _val) {
 val = _val;
 }
 
 Node(int _val, vector<Node*> _children) {
 val = _val;
 children = _children;
 }
 };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<Node*> Q;
        Q.push(NULL);
        Q.push(root);
        vector<int> res_level;
        while(!Q.empty()){
            Node* n = Q.front();
            Q.pop();
            
            if(n == NULL){
                if(!res_level.empty()){
                    res.push_back(res_level);
                    res_level.clear();
                }
                if(Q.empty())
                    break;
                Q.push(NULL);
            }
            else{
                for(Node* child:n->children){
                    Q.push(child);
                }
                res_level.push_back(n->val);
            }
        }
        return res;
    }
};
