//
//  binary_search_tree_iterator.cpp
//
//  Created by omlenka on 11/12/20.
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
class BSTIterator {
    vector<int> inorder;
    int curr;
    void doInorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        doInorder(root->left);
        inorder.push_back(root->val);
        doInorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        doInorder(root);
        curr = -1;
    }
    
    /** @return the next smallest number */
    int next() {
        curr++;
        return inorder[curr];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(curr + 1 < inorder.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
