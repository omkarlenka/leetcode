//
//  increasing_order_search_tree_lc897.cpp
//
//  Created by omlenka on 26/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

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
    TreeNode* increasingBSTUtil(TreeNode* root, TreeNode* &tail){
        if(root == NULL){
            return NULL;
        }
        
        if(root->left == NULL && root->right == NULL){
            tail = root;
            return root;
        }
        
        TreeNode* res = increasingBSTUtil(root->left, tail);
        
        if(tail){
            tail->right = root;
        }
        root->left = NULL;
        tail = root;
        
        root->right = increasingBSTUtil(root->right, tail);
        if(res == NULL){
            res = root;
        }
        return res;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* tail = NULL;
        return increasingBSTUtil(root, tail);
    }
};
