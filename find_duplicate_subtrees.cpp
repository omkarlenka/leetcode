//
//  find_duplicate_subtrees.cpp
//
//  Created by omlenka on 25/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

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
    string helper(TreeNode* root, unordered_set<TreeNode*> &res, unordered_map <string,TreeNode*> &S)
    {
        string lefts, rights, roots;
        if(root == NULL)
            return roots;
        
        if(root->left)
        {
            lefts = helper(root->left, res, S);
        }
        else
        {
            lefts = "#";
        }
        
        if(root->right)
        {
            rights = helper(root->right, res, S);
        }
        else
        {
            rights = "#";
        }
        
        roots = to_string(root->val) +"("+ lefts + rights + ")";
        if(S.find(roots) != S.end())
        {
            res.insert(S[roots]);
        }
        else
            S[roots] = root;
        
        return roots;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        unordered_map <string,TreeNode*> S;
        unordered_set<TreeNode*> res;
        helper(root, res, S);
        
        vector<TreeNode*> ress(res.begin(), res.end());
        return ress;
    }
};
