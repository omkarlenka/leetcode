//
//  all_possible_full_binary_trees_lc894.cpp
//
//  Created by omlenka on 19/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> roots;
        if(!(N & 1))
            return roots;
        TreeNode* root = new TreeNode(0);
        if(N == 1){
            roots.push_back(root);
            return roots;
        }
        
        for(int i=1;i<N;i+=2){
            vector<TreeNode*> lefts = allPossibleFBT(i);
            vector<TreeNode*> rights = allPossibleFBT(N-i-1);
            
            for(TreeNode* left:lefts){
                for(TreeNode* right:rights){
                    TreeNode *root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    roots.push_back(root);
                }
            }
        }
        
        return roots;
    }
};
int main() {
    Solution S;
    vector<TreeNode*> roots = S.allPossibleFBT(7);
    return 0;
}
