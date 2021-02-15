//
//  binary_tree_postorder_traversal_lc145.cpp
//
//  Created by omlenka on 15/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> S;
        S.push(root);
        S.push(NULL);
        if(root->right){
            S.push(root->right);
        }
        if(root->left){
            S.push(root->left);
        }
        
        
        while(!S.empty()){
            TreeNode* top = S.top();
            if(top == NULL){
                S.pop();
                TreeNode* top1 = S.top();
                S.pop();
                res.push_back(top1->val);
            }
            else{
                S.push(NULL);
                if(top->right){
                    S.push(top->right);
                }
                if(top->left){
                    S.push(top->left);
                }
            }
        }
        return res;
    }
};
