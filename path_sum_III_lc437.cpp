//
//  path_sum_III_lc437.cpp
//
//  Created by omlenka on 04/02/21.
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
    void findSumFromNode(TreeNode* root,int sum,int &res){
        if(root == NULL)
            return;
        if(sum == root->val)
            res++;
        
        findSumFromNode(root->left, sum - (root->val), res);
        findSumFromNode(root->right, sum - (root->val), res);
    }
    
    void pathSumUtil(TreeNode* root, int sum, int &res){
        if(root == NULL)
            return;
        
        findSumFromNode(root, sum, res);
        pathSumUtil(root->left, sum, res);
        pathSumUtil(root->right, sum, res);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        pathSumUtil(root,sum,res);
        return res;
    }
};
