//
//  max_width_of_binary_tree_lc662.cpp
//
//  Created by omlenka on 07/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

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
    typedef unsigned long ul;
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*,ul>> Q;
        Q.push_back({root,0});
        Q.push_back({NULL,0});
        int res = 1;
        
        while(!Q.empty()){
            pair<TreeNode*,ul> front = Q.front();
            Q.pop_front();
            
            if(front.first == NULL){
                if(Q.empty())
                    break;
                pair<TreeNode*,ul> tmp_front = Q.front();
                pair<TreeNode*,ul> back = Q.back();
                if(back.second - tmp_front.second + 1 > res)
                    res = back.second - tmp_front.second + 1;
                
                Q.push_back({NULL,0});
            }
            else{
                
                if(front.first->left){
                    Q.push_back(make_pair(front.first->left,2*(front.second)+1));
                }
                
                if(front.first->right){
                    Q.push_back(make_pair(front.first->right,2*(front.second)+2));
                }
            }
        }
        return res;
    }
};
