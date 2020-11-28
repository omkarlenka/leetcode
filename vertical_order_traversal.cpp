//
//  vertical_order_traversal.cpp
//
//  Created by omlenka on 28/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <queue>

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

class Compare{
public:
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        if(a.second < b.second)
            return true;
        if(a.second  ==  b.second)
            return (a.first < b.first);
        return false;
    }
};
 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        
        map<int, vector<pair<int,int>>> M;
        queue<pair<TreeNode*,int>> Q;   //Queue of node,width
        Q.push(make_pair(root,0));
        Q.push(pair<TreeNode*,int>(NULL,-1));  //delimiter between levels
        int level = 0;
        while(!Q.empty()){
            pair<TreeNode*,int> top = Q.front();
            Q.pop();
            TreeNode* node = top.first;
            int width = top.second;
            if(node == NULL){
                //this is delimiter between levels
                if(Q.empty())
                    break;
                level++;
                Q.push(pair<TreeNode*,int>(NULL,-1));
                continue;
            }
            if(node->left)
                Q.push(make_pair(node->left,width-1));
            if(node->right)
                Q.push(make_pair(node->right,width+1));
            M[width].push_back(make_pair(node->val,level));
        }
        auto itr = M.begin();
        while(itr != M.end()){
            sort(itr->second.begin(),itr->second.end(),Compare());
            vector<int> v;
            for(pair<int,int> p:itr->second){
                v.push_back(p.first);
            }
            res.push_back(v);
            itr++;
        }
        return res;
    }
};

int main() {
    Solution S;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> res = S.verticalTraversal(root);
    
    return 0;
}
