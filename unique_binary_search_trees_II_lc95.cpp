//
//  unique_binary_search_trees_II_lc95.cpp
//
//  Created by omlenka on 21/12/20.
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
    vector<TreeNode*> generateTreesUtil(int start,int end){
        vector<TreeNode*> res;
        if(start > end){
            return res;
        }
        
        if(start == end){
            TreeNode* root = new TreeNode(start);
            res.push_back(root);
            return res;
        }
        int n = end-start+1;
        for(int i = start;i<=end;i++){
            vector<TreeNode*> lefts;
            vector<TreeNode*> rights;
            if(i > start){
                lefts = generateTreesUtil(start,i-1);
            }
            
            if(i < end){
                rights = generateTreesUtil(i+1,end);
            }
            
            for(TreeNode* left: lefts){
                for(TreeNode* right: rights){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
            
            if(lefts.empty()){
                for(TreeNode* right: rights){
                    TreeNode* root = new TreeNode(i);
                    root->right = right;
                    res.push_back(root);
                }
            }
            
            if(rights.empty()){
                for(TreeNode* left: lefts){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesUtil(1,n);
    }
};

int main() {
    Solution S;
    vector<TreeNode*> res = S.generateTrees(3);
    
    return 0;
}
