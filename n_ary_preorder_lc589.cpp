//
//  n_ary_preorder_lc589.cpp
//
//  Created by omlenka on 23/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
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
    void preorderUtil(Node* root, vector<int> &res){
        if(root == NULL){
            return;
        }
        
        res.push_back(root->val);
        for(auto child: root->children){
            preorderUtil(child, res);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorderUtil(root,res);
        return res;
    }
};
