//
//  convert_bst_to_greater_tree_lc538.cpp
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
    void convertBSTUtil(TreeNode* root, int &sum){
        if(root == NULL){
            return;
        }
        
        convertBSTUtil(root->right,sum);
        sum += root->val;
        root->val = sum;
        convertBSTUtil(root->left,sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertBSTUtil(root, sum);
        return root;
    }
};
