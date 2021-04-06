//
//  n_ary_tree_postorder_lc590.cpp
//
//  Created by omlenka on 06/04/21.
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
    void postorderUtil(Node* root, vector<int> &res){
        if(root == NULL){
            return;
        }
        
        for(auto child:root->children){
            postorderUtil(child, res);
        }
        
        res.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorderUtil(root,res);
        return res;
    }
};
