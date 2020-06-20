//
//  balance_a_binary_search_tree.cpp
//
//  Created by omlenka on 21/06/20.
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
class Solution
{
    void getInorder(TreeNode *root, vector<int> &v)
    {
        if(root == NULL)
            return;
        
        getInorder(root->left, v);
        v.push_back(root->val);
        getInorder(root->right, v);
    }
    
    TreeNode* balanceBSTUtil(vector<int> &v, int s, int e)
    {
        if(s > e)
            return NULL;
        int m = s+(e-s)/2;
        if((e-s+1)%2 == 0)
            m++;
        TreeNode* root = new TreeNode(v[m]);
        root->left = balanceBSTUtil(v, s, m-1);
        root->right = balanceBSTUtil(v, m+1, e);
        
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root)
    {
        if(root == NULL)
            return root;
        vector<int> v;
        getInorder(root, v);
        return balanceBSTUtil(v, 0, v.size()-1);
    }
};

