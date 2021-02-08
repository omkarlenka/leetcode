//
//  swap_nodes_in_pairs_lc24.cpp
//
//  Created by omlenka on 08/02/21.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* res = head;;
        ListNode* prev_prev = NULL;
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while(prev && curr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            
            if(prev_prev != NULL){
                prev_prev->next = curr;
            }
            else{
                res = curr;
            }
            
            prev_prev = prev;
            prev->next = tmp;
            prev = tmp;
            if(prev)
                curr = prev->next;
        }
        
        return res;
    }
};
