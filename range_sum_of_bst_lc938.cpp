//
//  range_sum_of_bst_lc938.cpp
//
//  Created by omlenka on 01/04/21.
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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        if(root == NULL)
        {
            return res;
        }
        if(root->val < low){
            res += rangeSumBST(root->right, low, high);
        }
        else if(root->val > high){
            res += rangeSumBST(root->left, low, high);
        }
        else{
            res += root->val;
            res += rangeSumBST(root->right, low+1, high);
            res += rangeSumBST(root->left, low, high-1);
        }
        return res;
    }
};
