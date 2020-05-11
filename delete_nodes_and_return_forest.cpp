//
//  delete_nodes_and_return_forest.cpp
//
//  Created by omlenka on 11/05/20.
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void _delNodes(TreeNode* &root, vector<int>& to_delete, vector<TreeNode*> &res)
    {
        
        if(root == NULL)
            return;
        
        _delNodes(root->left, to_delete, res);
        _delNodes(root->right, to_delete, res);
        
        if(binary_search(to_delete.begin(),  to_delete.end(), root->val))
        {
            if(root->left)
                res.push_back(root->left);
            if(root->right)
                res.push_back(root->right);
            
            root = NULL;
            delete root;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        vector<TreeNode*> res;
        sort(to_delete.begin(), to_delete.end());
        _delNodes(root, to_delete, res);
        if(root)
            res.push_back(root);
        
        return res;
    }
};
