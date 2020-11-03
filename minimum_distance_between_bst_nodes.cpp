//
//  minimum_distance_between_bst_nodes.cpp
//
//  Created by omlenka on 03/11/20.
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
    void minDiffBST_Util(TreeNode* root, int &prev, int &res){
        if(root == NULL)
            return;
        minDiffBST_Util(root->left, prev, res);
        if(prev != INT_MAX){
            if(root->val - prev < res)
                res = root->val - prev;
        }
        prev = root->val;
        minDiffBST_Util(root->right, prev, res);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        int prev = INT_MAX;
        minDiffBST_Util(root, prev, res);
        return res;
    }
};
