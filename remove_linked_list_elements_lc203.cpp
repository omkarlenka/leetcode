//
//  remove_linked_list_elements_lc203.cpp
//
//  Created by omlenka on 06/03/21.
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        ListNode* curr = head;
        while(curr){
            if(curr == head && curr->val == val){
                curr = curr->next;
                delete head;
                head = curr;
            }
            else if(curr->next && curr->next->val == val){
                ListNode* tmp = curr->next->next;
                delete curr->next;
                curr->next = tmp;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};
