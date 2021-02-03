//
//  path_sum_II_lc113.cpp
//
//  Created by omlenka on 03/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
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
    void pathSumUtil(TreeNode* root, int targetSum, vector<int> &cur_path, vector<vector<int>> &res){
        if(root == NULL)
            return;
        cur_path.push_back(root->val);
        if(!root->left && !root->right){
            if(targetSum-(root->val) == 0){
                res.push_back(cur_path);
            }
        }
        
        pathSumUtil(root->left, targetSum-(root->val), cur_path, res);
        pathSumUtil(root->right, targetSum-(root->val), cur_path, res);
        
        cur_path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> cur_path;
        pathSumUtil(root, targetSum, cur_path, res);
        return res;
    }
};
