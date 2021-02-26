//
//  cousins_in_binary_tre_lc993.cpp
//
//  Created by omlenka on 26/02/21.
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
    bool isCousinsUtil(TreeNode* root, int x, int y, int k, int &x_k, int &y_k){
        if(root->val == x){
            x_k = k;
        }
        else if(root->val == y){
            y_k = k;
        }
        
        if(root->left && root->right){
            if((root->left->val == x && root->right->val == y)||
               (root->left->val == y && root->right->val == x)){
                return false;
            }
        }
        if(root->left && !isCousinsUtil(root->left,x,y,k+1,x_k,y_k)){
            return false;
        }
        if(root->right && !isCousinsUtil(root->right,x,y,k+1,x_k,y_k)){
            return false;
        }
        return true;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int x_k = 0, y_k = 0;
        if(!isCousinsUtil(root,x,y,0,x_k,y_k)){
            return false;
        }
        if(x_k == y_k){
            return true;
        }
        return false;
    }
};
