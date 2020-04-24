//
//  remove_nth_from_end.cpp
//
//  Created by omlenka on 24/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(n--)
        {
            if(fast->next)
                fast = fast->next;
            else
            {
                //Remove head
                ListNode*  tmp = head->next;
                head = head->next;
                return head;
            }
        }
        
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        return  head;
    }
};

