//
//  kth_smallest_in_bst.cpp
//
//  Created by omlenka on 05/05/20.
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
public:
    int kthSmallest(TreeNode* root, int k)
    {
        stack<TreeNode *> s;
        int count = 0;
        s.push(root);
        while(root || !s.empty())
        {
            while(root && root->left)
            {
                root = root->left;
                s.push(root);
            }
            
            TreeNode* n = s.top();
            s.pop();
            count++;
            if(count == k)
                return n->val;
            
            if(n->right)
            {
                s.push(n->right);
                root = n->right;
            }
            else
                root = NULL;
        }
        return -1;
    }
};
