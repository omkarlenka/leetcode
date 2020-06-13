//
//  symmetric_tree.cpp
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
    bool isSymmetricUtil(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2)
            return true;
        
        if((root1 && !root2) || (root2 && !root1))
            return false;
        
        if(root1->val != root2->val)
            return false;
        
        return isSymmetricUtil(root1->right, root2->left) && isSymmetricUtil(root1->left, root2->right);
    }
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL)
            return true;
        return isSymmetricUtil(root->left, root->right);
    }
};
