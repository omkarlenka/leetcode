//
//  flip_equivalent_binary_trees.cpp
//
//  Created by omlenka on 25/04/20.
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        else if(root1 == NULL || root2 == NULL || root1->val != root2->val)
            return false;
        
        return (flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right)) ||
        (flipEquiv(root1->right,root2->left) && flipEquiv(root1->left,root2->right));
    }
};
