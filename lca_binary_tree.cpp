//
//  lca_binary_tree.cpp
//
//  Created by omlenka on 18/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL || root == p  || root == q)
            return root;
        
        TreeNode* left_lca = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_lca = lowestCommonAncestor(root->right, p, q);
        
        if(left_lca && right_lca)
            return root;
        if(left_lca)
            return left_lca;
        if(right_lca)
            return right_lca;
        
        
        return NULL;
    }
};
