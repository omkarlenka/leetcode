//
//  invert_binary_tree_lc226.cpp
//
//  Created by omlenka on 07/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    
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
        TreeNode* invertTree(TreeNode* root) {
            if(root == NULL)
                return NULL;
            TreeNode* tmp = root->right;
            root->right = invertTree(root->left);
            root->left = invertTree(tmp);
            return root;
        }
    };
