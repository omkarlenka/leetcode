//
//  populating_next_right_pointers_II.cpp
//
//  Created by omlenka on 29/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <queue>

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
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        queue<Node*> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            Node* node = Q.front();
            Q.pop();
            if(node == NULL){
                if (Q.empty()){
                    break;
                }
                Q.push(NULL);
                continue;
            }
            Node* next_node = Q.front();
            if(next_node != NULL){
                node->next = next_node;
            }
            if(node->left){
                Q.push(node->left);
            }
            if(node->right){
                Q.push(node->right);
            }
        }
        return root;
    }
};
