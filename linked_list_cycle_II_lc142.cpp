//
//  linked_list_cycle_II_lc142.cpp
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* slow = head->next;
        ListNode* fast = NULL;
        if(head->next && head->next->next){
            fast = head->next->next;
        }
        
        while(slow && fast){
            if(slow == fast){
                break;
            }
            slow = slow->next;
            if(fast->next && fast->next->next){
                fast = fast->next->next;
            }
            else{
                fast = NULL;
            }
        }
        if(fast == NULL){
            return NULL;
        }
        
        slow = head;
        while(slow){
            if(fast == slow){
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
