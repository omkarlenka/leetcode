//
//  sum_of_left_leaves.cpp
//
//  Created by omlenka on 27/11/20.
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
    void sumUtil(TreeNode* root, bool isLeft, int &res){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            if(isLeft){
                res += root->val;
            }
            return;
        }
        
        sumUtil(root->left, true, res);
        sumUtil(root->right, false, res);
        
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        sumUtil(root, false, res);
        return res;
    }
};
