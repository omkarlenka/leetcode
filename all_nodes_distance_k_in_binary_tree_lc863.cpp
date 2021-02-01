//
//  all_nodes_distance_k_in_binary_tree_lc863.cpp
//
//  Created by omlenka on 01/02/21.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void findNodeDown(TreeNode* node, int K, vector<int> &res){
        if(node == NULL || K < 0)
            return;
        if(K == 0){
            res.push_back(node->val);
            return;
        }
        
        findNodeDown(node->left, K-1, res);
        findNodeDown(node->right, K-1, res);
    }
    
    int distanceKUtil(TreeNode* root, TreeNode* target, int K, vector<int> &res){
        if(root == NULL)
            return -1;
        if(root == target){
            findNodeDown(root, K, res);
            return 1;
        }
        
        int dist_left = distanceKUtil(root->left, target, K, res);
        int dist_right;
        if(dist_left == -1)
            dist_right = distanceKUtil(root->right, target, K, res);
        
        if(dist_left != -1){
            if(dist_left == K){
                res.push_back(root->val);
                return 1+dist_left;
            }
            else{
                findNodeDown(root->right, K-dist_left-1, res);
                return dist_left+1;
            }
        }
        else if(dist_right != -1){
            if(dist_right == K){
                res.push_back(root->val);
                return 1+dist_right;
            }
            else{
                findNodeDown(root->left, K-dist_right-1, res);
                return dist_right+1;
            }
        }
        
        return -1;
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        distanceKUtil(root, target, K, res);
        return res;
    }
};
