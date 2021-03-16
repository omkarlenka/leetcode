//
//  insertion_sort_list_lc_.147cpp
//
//  Created by omlenka on 16/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void insert(ListNode* &head, ListNode* node){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(node->val > curr->val){
            prev = curr;
            curr = curr->next;
        }
        if(prev == NULL){
            //Insert before head
            node->next = head;
            head = node;
        }
        else{
            prev->next = node;
            node->next = curr;
        }
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* curr = head;
        while(curr != NULL){
            if(curr->next && curr->next->val < curr->val){
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                insert(head,tmp);
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};

