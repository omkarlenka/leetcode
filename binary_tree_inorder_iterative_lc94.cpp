//
//  binary_tree_inorder_iterative_lc94.cpp
//
//  Created by omlenka on 08/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()){
            while(root && root->left){
                stk.push(root->left);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            if(root->right)
            {
                stk.push(root->right);
                root = root->right;
            }
            else{
                root = NULL;
            }
        }
        return res;
    }
};
