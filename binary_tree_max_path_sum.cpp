//
//  binary_tree_max_path_sum.cpp
//
//  Created by omlenka on 30/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
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
public:
    int maxpathSum_Util(TreeNode* root, int &max_sum)
    {
        if(root == NULL)
            return 0;
        
        int left_sum = maxpathSum_Util(root->left, max_sum);
        int right_sum = maxpathSum_Util(root->right, max_sum);
        int sum = root->val;
        if(left_sum >= 0 || right_sum >= 0)
            sum += max(left_sum,right_sum);
        
        if(sum > max_sum)
            max_sum = sum;
        
        if(root->val+left_sum+right_sum > max_sum)
            max_sum = root->val+left_sum+right_sum;
        
        return sum;
        
    }
    int maxPathSum(TreeNode* root)
    {
        int max_sum = INT_MIN;
        maxpathSum_Util(root, max_sum);
        return max_sum;
    }
};
