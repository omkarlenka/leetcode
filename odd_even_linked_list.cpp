//
//  odd_even_linked_list.cpp
//
//  Created by omlenka on 21/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
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
    ListNode* oddEvenList(ListNode* head)
    {
        if(head == NULL)
            return head;
        ListNode *odd = head;
        ListNode* even;
        
        if(head->next)
            even = head->next;
        else
            return head;
        
        bool removeOdd = true;
        ListNode* cur = even;
        while(cur->next)
        {
            ListNode* tmp = even->next;
            even->next = tmp->next;
            if(removeOdd)
            {
                tmp->next = odd->next;
                odd->next = tmp;
                odd = tmp;
                removeOdd = false;
            }
            else
            {
                tmp->next = even->next;
                even->next = tmp;
                even = tmp;
                removeOdd = true;
            }
            
            cur = even;
        }
        return head;
    }
};


