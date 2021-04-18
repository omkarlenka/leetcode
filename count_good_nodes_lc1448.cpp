//
//  count_good_nodes_lc1448.cpp
//
//  Created by omlenka on 18/04/21.
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
    void goodNodesUtil(TreeNode* root, int maxTillHere, int &res){
        if(root == NULL){
            return;
        }
        
        if(root->val >= maxTillHere){
            res++;
            maxTillHere = root->val;
        }
        goodNodesUtil(root->left,maxTillHere,res);
        goodNodesUtil(root->right,maxTillHere,res);
    }
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        int maxTillHere = INT_MIN;
        goodNodesUtil(root, maxTillHere, res);
        return res;
    }
};
