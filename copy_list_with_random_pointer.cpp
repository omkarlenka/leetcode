//
//  copy_list_with_random_pointer.cpp
//
//  Created by omlenka on 28/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* next;
 Node* random;
 
 Node(int _val) {
 val = _val;
 next = NULL;
 random = NULL;
 }
 };
 */

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if(head == NULL)
            return NULL;
        
        Node* curr = head;
        Node* head_copy = NULL;
        Node* curr_copy = NULL;
        unordered_map<Node*, Node*>  m;
        
        while(curr)
        {
            if(!curr_copy)
            {
                head_copy = new Node(curr->val);
                curr_copy = head_copy;
            }
            else
            {
                Node* tmp = new Node(curr->val);
                curr_copy->next = tmp;
                curr_copy = tmp;
            }
            m[curr] = curr_copy;
            curr = curr->next;
        }
        curr = head;
        curr_copy = head_copy;
        while(curr)
        {
            if(curr->random == NULL)
            {
                curr_copy->random = NULL;
            }
            else
            {
                curr_copy->random = m[curr->random];
            }
            curr = curr->next;
            curr_copy = curr_copy->next;
        }
        return head_copy;
    }
};
