//
//  diameter_of_binary_tree.cpp
//
//  Created by omlenka on 19/04/20.
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
    int diameterOfBinaryTree_Util(TreeNode* root, int &max)
    {
        if((root == NULL) || (root->left == NULL && root->right == NULL))
            return 0;
        int left = 0, right = 0;
        if(root->left)
            left = 1+ diameterOfBinaryTree_Util(root->left, max);
        if(root->right)
            right = 1+ diameterOfBinaryTree_Util(root->right, max);
        
        int path = left+right;
        if(path > max)
            max = path;
        
        return std::max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root)
    {
        int max = 0;
        diameterOfBinaryTree_Util(root, max);
        return max;
    }
};
