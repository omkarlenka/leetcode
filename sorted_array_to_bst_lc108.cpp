//
//  sorted_array_to_bst_lc108.cpp
//
//  Created by omlenka on 10/01/21.
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
    TreeNode* sortedArrayToBSTUtil(vector<int> &nums, int start, int end){
        if(start > end)
            return NULL;
        
        int m = end - (end - start)/2;
        
        TreeNode* root = new TreeNode(nums[m]);
        root->left = sortedArrayToBSTUtil(nums, start, m-1);
        root->right = sortedArrayToBSTUtil(nums, m+1, end);
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTUtil(nums, 0 , nums.size()-1);
    }
};
