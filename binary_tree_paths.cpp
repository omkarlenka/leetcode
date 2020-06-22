//
//  binary_tree_paths.cpp
//
//  Created by omlenka on 22/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
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
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string > res;
        if(root == NULL)
            return res;
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> l,r;
        if(root->left)
        {
            l = binaryTreePaths(root->left);
            for(string &s: l)
                s = to_string(root->val) + "->" + s;
        }
        if(root->right)
        {
            r = binaryTreePaths(root->right);
            for(string &s: r)
                s = to_string(root->val) + "->" + s;
        }
        
        l.insert(l.end(),r.begin(),r.end());
        return l;
    }
};
