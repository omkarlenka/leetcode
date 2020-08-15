//
//  populating_next_right_pointer.cpp
//
//  Created by omlenka on 15/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* left;
 Node* right;
 Node* next;
 
 Node() : val(0), left(NULL), right(NULL), next(NULL) {}
 
 Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
 
 Node(int _val, Node* _left, Node* _right, Node* _next)
 : val(_val), left(_left), right(_right), next(_next) {}
 };
 */

class Solution {
public:
    Node* connect(Node* root)
    {
        if(root == NULL)
            return root;
        
        if(root->left)
            root->left->next = root->right;
        
        Node* l = root->left;
        Node* r = root->right;
        
        while(l && l->right)
        {
            l->right->next = r->left;
            l = l->right;
            r = r->left;
        }
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};
