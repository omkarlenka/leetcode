//
//  sum_of_root_to_leaf_binary_lc1022.cpp
//
//  Created by omlenka on 30/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

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
    int stringToBin(string s){
        int len = s.length();
        int res = 0;
        for(int i = 0;i<len;i++){
            res += ((s[i]-'0')*pow(2,len-i-1));
        }
        return res;
    }
    void sumUtil(TreeNode* root, string binary, int &res){
        if(root == NULL){
            return;
        }
        binary += to_string(root->val);
        
        if(!root->left && !root->right){
            res += stringToBin(binary);
            return;
        }
        
        sumUtil(root->left,binary, res);
        sumUtil(root->right,binary, res);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        string binary;
        int res = 0;
        sumUtil(root, binary, res);
        return res;
    }
};
