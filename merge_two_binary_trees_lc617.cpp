//
//  merge_two_binary_trees_lc617.cpp
//
//  Created by omlenka on 01/01/21.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2){
            return NULL;
        }
        int val = 0;
        if(t1){
            val += t1->val;
        }
        if(t2){
            val += t2->val;
        }
        
        TreeNode *node = new TreeNode(val);
        if(t1 && t2){
            node->left = mergeTrees(t1->left, t2->left);
            node->right = mergeTrees(t1->right, t2->right);
        }
        else if(t1){
            node->left = mergeTrees(t1->left, NULL);
            node->right = mergeTrees(t1->right, NULL);
        }
        else{
            node->left = mergeTrees(NULL, t2->left);
            node->right = mergeTrees(NULL, t2->right);
        }
        
        return node;
    }
};
