//
//  merge_two_lists.cpp
//
//  Created by omlenka on 25/04/20.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode *head;
        
        if(l1->val < l2->val)
        {
            ListNode *n1 = l1->next;
            l1->next = mergeTwoLists(n1,l2);
            head = l1;
        }
        else
        {
            ListNode *n2 = l2->next;
            l2->next = mergeTwoLists(l1, n2);
            head = l2;
        }
        
        return head;
    }
};
