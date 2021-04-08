//
//  partition_list_lc86.cpp
//
//  Created by omlenka on 08/04/21.
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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = NULL;
        ListNode* tail1 = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr){
            if(curr->val < x) {
                ListNode* tmp = curr->next;
                if(head1 == NULL){
                    head1 = curr;
                    tail1 = curr;
                }
                else{
                    tail1->next = curr;
                    tail1 = tail1->next;
                }
                
                if(prev){
                    prev->next = tmp;
                    curr->next = NULL;
                    curr = tmp;
                }
                else{
                    head = tmp;
                    curr = tmp;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        if(tail1){
            tail1->next = head;
            head = head1;
        }
        return head;
    }
};

