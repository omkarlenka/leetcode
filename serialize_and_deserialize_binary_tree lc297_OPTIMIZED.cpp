//
//  serialize_and_deserialize_binary_tree lc297_OPTIMIZED.cpp
//
//  Created by omlenka on 26/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
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
class Codec {
    string serializeUtil(TreeNode* root){
        string res = "";
        if(root == NULL){
            return res;
        }
        queue<TreeNode*> Q;
        
        Q.push(root);
        while(!Q.empty()){
            TreeNode* n = Q.front();
            Q.pop();
            
            if(n == NULL){
                res += "N ";
            }
            else{
                res += to_string(n->val) + " ";
            }
            if(n){
                Q.push(n->left);
                Q.push(n->right);
            }
        }
        return res;
        
    }
    TreeNode* deserializeUtil(string data){
        if(data.empty())
            return NULL;
        stringstream ss(data);
        string word;
        vector<string> v;
        
        while(ss >> word){
            v.push_back(word);
        }
        
        TreeNode* root = new TreeNode(stoi(v[0]));
        queue<TreeNode*> Q;
        Q.push(root);
        int start = 0;
        
        while(!Q.empty()){
            TreeNode* currentNode = Q.front();
            Q.pop();
            int i = start+1;
            int j = start+2;
            
            if(i < v.size() && v[i] != "N"){
                TreeNode* n = new TreeNode(stoi(v[i]));
                currentNode->left = n;
                Q.push(n);
            }
            if(j < v.size() && v[j] != "N"){
                TreeNode* n = new TreeNode(stoi(v[j]));
                currentNode->right = n;
                Q.push(n);
            }
            
            start += 2;
        }
        
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serializeUtil(root);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserializeUtil(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
