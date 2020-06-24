//
//  flatten_binary_tree.cpp
//
//  Created by omlenka on 24/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

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
    void flattenUtil(TreeNode* root, TreeNode* &tail)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            tail = root;
            return;
        }
        flattenUtil(root->left,tail);
        TreeNode* tmp = root->right;
        if(root->left)
        {
            root->right = root->left;
            root->left = NULL;
            if(tail)
            {
                tail->right = tmp;
            }
        }
        flattenUtil(tmp,tail);
        
    }
public:
    void flatten(TreeNode* root)
    {
        TreeNode* tail = NULL;
        flattenUtil(root, tail);
    }
};


