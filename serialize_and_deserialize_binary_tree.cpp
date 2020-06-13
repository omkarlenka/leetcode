//
//  serialize_and_deserialize_binary_tree.cpp
//
//  Created by omlenka on 13/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
public:
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec
{
    void serializeUtil(TreeNode* root, string &res)
    {
        if(root == NULL)
            return;
        
        res += to_string(root->val);
        
        if(root->left)
        {
            res += "{";
            serializeUtil(root->left, res);
            res += "}";
        }
        if(root->right)
        {
            res += "(";
            serializeUtil(root->right, res);
            res += ")";
        }
    }
    
    TreeNode* deserializeUtil(string data, int &s, int &e)
    {
        TreeNode* root = NULL;
        string val = "";
        bool negative = false;
        while(s <= e)
        {
            if(isdigit(data[s]))
            {
                val += string(1,data[s]);
            }
            else if(data[s] == '-')
            {
                negative = true;
            }
            else
            {
                if(!val.empty())
                {
                    int value = stoi(val);
                    if(negative)
                    {
                        value *= -1;
                        negative = false;
                    }
                    root = new TreeNode(value);
                    val = "";
                }
                if(data[s] == '{')
                {
                    s++;
                    root->left = deserializeUtil(data, s, e);
                }
                else if(data[s] == '(')
                {
                    s++;
                    root->right = deserializeUtil(data, s, e);
                }
                else if(data[s] == '}' || data[s] == ')')
                {
                    return root;
                }
            }
            s++;
        }
        if(!val.empty())
        {
            int value = stoi(val);
            if(negative)
            {
                value *= -1;
                negative = false;
            }
            root = new TreeNode(value);
        }
        return root;
    }
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string res = "";
        serializeUtil(root, res);
        
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        int s = 0, e = data.size()-1;
        return deserializeUtil(data,s,e);
    }
};

int main()
{
    
    // Your Codec object will be instantiated and called as such:
    TreeNode* root = new TreeNode(-10);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
    
    Codec codec;
    string s = codec.serialize(root);
    TreeNode* r = codec.deserialize(s);

    return 0;
}
