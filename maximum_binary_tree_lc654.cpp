//
//  fmaximum_binary_tree_lc654.cpp
//
//  Created by omlenka on 29/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

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
    int getMax(vector<int> &nums, int s, int e){
        int max = s;
        for(int i = s+1;i<=e;i++){
            if(nums[i] > nums[max]){
                max = i;
            }
        }
        
        return max;
    }
    
    TreeNode* util(vector<int> &nums, int s, int e){
        if(s > e)
            return NULL;
        
        if(s==e){
            return new TreeNode(nums[s]);
        }
        int index = getMax(nums, s, e);
        
        TreeNode* root = new TreeNode(nums[index]);
        root->left = util(nums,s,index-1);
        root->right = util(nums,index+1,e);
        
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return util(nums, 0, nums.size()-1);
    }
};
