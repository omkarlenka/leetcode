//
//  vlidate_binary_search_tree.cpp
//
//  Created by omlenka on 12/06/20.
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
    bool isValidBSTUtil(TreeNode* root, TreeNode* &prev)
    {
        if(root == NULL)
            return true;
        
        if(!isValidBSTUtil(root->left, prev))
            return false;
        
        if(prev && root->val <= prev->val)
            return false;
        
        prev = root;
        return isValidBSTUtil(root->right, prev);
    }
public:
    
    bool isValidBST(TreeNode* root)
    {
        TreeNode *prev = NULL;
        
        return isValidBSTUtil(root, prev);
    }
    
};
