//
//  sum_root_to_leadf_numbers_lc129.cpp
//
//  Created by omlenka on 07/03/21.
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
    void sumNumbersUtil(TreeNode* root, int &current_sum, int &total_sum){
        if(root == NULL){
            return;
        }
        
        current_sum = (current_sum * 10) + root->val;
        
        if(root->left == NULL && root->right == NULL){
            total_sum += current_sum;
        }
        
        sumNumbersUtil(root->left, current_sum, total_sum);
        sumNumbersUtil(root->right, current_sum, total_sum);
        
        current_sum /= 10;
    }
    
public:
    int sumNumbers(TreeNode* root) {
        int current_sum = 0, total_sum = 0;
        
        sumNumbersUtil(root,current_sum, total_sum);
        return total_sum;
    }
};
