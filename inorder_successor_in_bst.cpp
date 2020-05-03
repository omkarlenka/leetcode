//
//  inorder_successor_in_bst.cpp
//
//  Created by omlenka on 03/05/20.
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
    TreeNode* _inorderSuccessor(TreeNode* root, TreeNode* p, TreeNode* inorderSucc)
    {
        if(root)
        {
            if(root == p)
                return inorderSucc;
            if(p->val < root->val)
            {
                return _inorderSuccessor(root->left, p, root);
            }
            else
            {
                return _inorderSuccessor(root->right, p, inorderSucc);
            }
        }
        
        return NULL;
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        TreeNode*  n  = p->right;
        if(n)
        {
            while(n)
            {
                if(n->left)
                    n = n->left;
                else
                    return n;
            }
            return n;
        }
        
        return _inorderSuccessor(root, p, NULL);
    }
};
