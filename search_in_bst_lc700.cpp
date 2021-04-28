//
//  search_in_bst_lc700.cpp
//
//  Created by omlenka on 24/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>]

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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = NULL;
        while(root){
            if(root->val == val){
                res = root;
                break;
            }
            else if(root->val < val){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return res;
    }
};
