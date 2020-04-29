//
//  add_two_numbers.cpp
//
//  Created by omlenka on 29/04/20.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else  if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        
        ListNode* head = NULL;
        ListNode* cur = head;
        int carry = 0;
        int val;
        while(l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            
            if(sum >= 10)
            {
                val = sum % 10;
                carry = 1;
            }
            else
            {
                val = sum;
                carry = 0;
            }
            
            ListNode* n = new ListNode(val);
            if(cur)
            {
                cur->next = n;
                cur = cur->next;
            }
            else
            {
                head = n;
                cur = head;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* r = NULL;
        if(l1)
        {
            r = l1;
        }
        else if(l2)
        {
            r = l2;
        }
        
        while(r)
        {
            int sum = r->val + carry;
            if(sum >= 10)
            {
                val = sum % 10;
                carry = 1;
            }
            else
            {
                val = sum;
                carry = 0;
            }
            ListNode* n = new ListNode(val);
            cur->next = n;
            cur = cur->next;
            r = r->next;
        }
        if(carry)
        {
            ListNode* n = new ListNode(carry);
            cur->next = n;
            cur = cur->next;
        }
        return head;
    }
};
