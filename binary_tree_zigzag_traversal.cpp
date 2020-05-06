//
//  binary_tree_zigzag_traversal.cpp
//
//  Created by omlenka on 06/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

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
    int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        return(1 + max(height(root->left),  height(root->right)));
    }
    
    void _zigzagLevelOrder(TreeNode* root, int level, int current_level, vector<vector<int>> &res)
    {
        if(root == NULL)
            return;
        
        if(level == 0)
        {
            if(res[current_level].empty())
            {
                vector<int> v;
                v.push_back(root->val);
                res[current_level] = v;
            }
            else
            {
                res[current_level].push_back(root->val);
            }
        }
        else
        {
            _zigzagLevelOrder(root->left, level-1,current_level, res);
            _zigzagLevelOrder(root->right, level-1,current_level, res);
        }
    }
public:
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        int h = height(root);
        vector<vector<int>> res(h);
        bool l2r = true;
        
        for(int l = 0;l<h;l++)
        {
            _zigzagLevelOrder(root,l,l,res);
            if(!l2r)
            {
                reverse(res[l].begin(), res[l].end());
            }
            l2r = !l2r;
        }
        
        return res;
    }
};
