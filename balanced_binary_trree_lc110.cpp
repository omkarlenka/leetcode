//
//  balanced_binary_trree_lc110.cpp
//
//  Created by omlenka on 09/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
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
    int isBalancedUtil(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int left_h = isBalancedUtil(root->left);
        if(left_h == -1){
            return -1;
        }
        
        int right_h = isBalancedUtil(root->right);
        if(right_h == -1){
            return -1;
        }
        
        if(abs(right_h - left_h) > 1){
            return -1;
        }
        
        return max(left_h,right_h)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(isBalancedUtil(root) == -1)
            return false;
        return true;
    }
};
