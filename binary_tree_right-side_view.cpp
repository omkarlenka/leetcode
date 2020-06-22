//
//  binary_tree_right-side_view.cpp
//
//  Created by omlenka on 22/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

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
class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> Q;
        Q.push(NULL);
        Q.push(root);
        bool first = false;
        
        while(!Q.empty())
        {
            TreeNode* n = Q.front();
            Q.pop();
            
            if(n == NULL)
            {
                first = true;
            }
            else
            {
                if(first)
                {
                    Q.push(NULL);
                    res.push_back(n->val);
                    first = false;
                }
                if(n->right)
                    Q.push(n->right);
                if(n->left)
                    Q.push(n->left);
            }
        }
        return res;
    }
};

