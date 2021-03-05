//
//  lowest_common_ancestor_bst_lc235.cpp
//
//  Created by omlenka on 05/03/21.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* LcaUtil(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL  || root == p || root == q){
            return root;
        }
        TreeNode* res;
        if(root->val < p->val){
            res = LcaUtil(root->right, p, q);
        }
        else if(root->val > q->val){
            res = LcaUtil(root->left, p, q);
        }
        return res;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* greater = NULL;
        TreeNode* smaller = NULL;
        
        if(p->val > q->val){
            greater = p;
            smaller = q;
        }
        else{
            greater = q;
            smaller = p;
        }
        return LcaUtil(root, smaller, greater);
    }
};
