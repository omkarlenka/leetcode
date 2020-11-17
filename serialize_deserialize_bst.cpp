//
//  serialize_deserialize_bst.cpp
//
//  Created by omlenka on 17/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
    void serialize_util(TreeNode *root, string &serialized_tree){
        if(root == NULL)
            return;
        serialized_tree += to_string(root->val) + ",";
        serialize_util(root->left, serialized_tree);
        serialize_util(root->right, serialized_tree);
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized_tree;
        serialize_util(root, serialized_tree);
        return serialized_tree;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<TreeNode*> stk;
        char *c_data = &data[0];
        char* token = strtok(c_data, ",");
        TreeNode *root = NULL;
        while(token != NULL){
            
            int val = atoi(token);
            TreeNode *n = new TreeNode(val);
            
            if(root == NULL){
                root = n;
                stk.push(root);
            }
            else{
                TreeNode *top_node = stk.top();
                if(val < top_node->val){
                    top_node->left = n;
                    stk.push(n);
                }
                else{
                    TreeNode *prev_top_node = NULL;
                    while(!stk.empty() && val > top_node->val){
                        stk.pop();
                        prev_top_node = top_node;
                        if(!stk.empty())
                            top_node = stk.top();
                    }
                    if(prev_top_node){
                        prev_top_node->right = n;
                    }
                    stk.push(n);
                }
            }
            token = strtok(NULL, ",");
        }
        
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    Codec codec;
    string s = codec.serialize(root);
    TreeNode* res = codec.deserialize(s);
    
    return 0;
}
