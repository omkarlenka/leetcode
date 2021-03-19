//
//  binary_tree_preorder_iterative_lc144.cpp
//
//  Created by omlenka on 19/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        
        stack<TreeNode*> S;
        S.push(root);
        
        while(!S.empty()){
            TreeNode* top = S.top();
            
            while(top->left){
                res.push_back(top->val);
                top = top->left;
                S.push(top);
            }
            res.push_back(top->val);
            
            while(!S.empty()){
                TreeNode* top1 = S.top();
                S.pop();
                if(top1->right){
                    S.push(top1->right);
                    break;
                }
            }
        }
        return res;
    }
};
