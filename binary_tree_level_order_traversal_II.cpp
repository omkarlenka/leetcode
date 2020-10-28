//
//  binary_tree_level_order_traversal_II.cpp
//
//  Created by omlenka on 28/10/20.
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
    void levelOrderBottom_Util(TreeNode* root, int level, vector<vector<int>> & res)
    {
        if(root == NULL)
            return;
        
        if(res.size() < level+1)
        {
            vector<int> v;
            v.push_back(root->val);
            res.push_back(v);
        }
        else
        {
            res[level].push_back(root->val);
        }
        levelOrderBottom_Util(root->left, level+1, res);
        levelOrderBottom_Util(root->right, level+1, res);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderBottom_Util(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
