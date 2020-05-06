//
//  construct_binary_tree_from_inorder_preorder.cpp
//
//  Created by omlenka on 06/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
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
    int  getIndex(vector<int> &inorder, int val)
    {
        for(int i = 0;i<inorder.size();i++)
        {
            if(inorder[i] == val)
                return i;
        }
        return -1;
    }
    
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int &index)
    {
        if(preorder.empty() || inorder.empty())
        {
            index--;
            return NULL;
        }
        TreeNode* root = NULL;
        
        while(index<preorder.size())
        {
            int in = getIndex(inorder,  preorder[index]);
            if(in == -1)
            {
                index--;
                return root;
            }
            root = new TreeNode(preorder[index]);
            vector<int> left_inorder(inorder.begin(), inorder.begin() + in);
            root->left = _buildTree(preorder, left_inorder, ++index);
            
            vector<int> right_inorder(inorder.begin()+in+1, inorder.end());
            root->right = _buildTree(preorder, right_inorder, ++index);
            if(root->left == NULL && root->right == NULL)
                return root;
            index++;
        }
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int index = 0;
        return _buildTree(preorder, inorder, index);
    }
};
