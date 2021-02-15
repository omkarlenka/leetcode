//
//  binary_tree_postorder_traversal_lc145.cpp
//
//  Created by omlenka on 15/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include  <vector>

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
    void postorderTraversalUtil(TreeNode* root, vector<int> &res){
        if(root == NULL)
            return;
        postorderTraversalUtil(root->left, res);
        postorderTraversalUtil(root->right, res);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversalUtil(root, res);
        return res;
    }
};
