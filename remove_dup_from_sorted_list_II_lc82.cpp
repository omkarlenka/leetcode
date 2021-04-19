//
//  remove_dup_from_sorted_list_II_lc82.cpp
//
//  Created by omlenka on 19/04/21.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;
        int prev_val = -101;
        ListNode* curr = head;
        while(curr){
            if((prev_val == curr->val) ||(curr->next && curr->val == curr->next->val)){
                ListNode *next = curr->next;
                curr->next = NULL;
                if(prev){
                    prev->next = next;
                }
                prev_val = curr->val;
                if(curr == head){
                    if(next){
                        head = next;
                    }
                    else{
                        head = NULL;
                    }
                }
                curr = next;
            }
            else{
                prev = curr;
                prev_val = prev->val;
                curr = curr->next;
            }
        }
        return head;
    }
};
