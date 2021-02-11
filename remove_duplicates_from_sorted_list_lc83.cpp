//
//  remove_duplicates_from_sorted_list_lc83.cpp
//
//  Created by omlenka on 10/02/21.
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
        if(head == NULL)
            return head;
        ListNode* ptr = head;
        
        while(ptr){
            if(ptr->next && ptr->next->val == ptr->val){
                ListNode* tmp = ptr->next;
                ptr->next = ptr->next->next;
                delete tmp;
            }
            else{
                ptr = ptr->next;
            }
        }
        return head;
    }
};
