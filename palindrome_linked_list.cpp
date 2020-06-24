//
//  palindrome_linked_list.cpp
//
//  Created by omlenka on 24/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

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

// 1->2->3->2->1
// 1->2->3->3->2->1
class Solution {
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            if(tmp == NULL)
                head = curr;
            curr = tmp;
        }
        return head;
    }
    bool compare(ListNode* h1, ListNode* h2)
    {
        ListNode* cur1 = h1;
        ListNode* cur2 = h2;
        
        while(cur1 && cur2)
        {
            if(cur1->val == cur2->val)
            {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            else
                return false;
        }
        if(cur1 == NULL && cur2 == NULL)
            return true;
        else
            return false;
    }
public:
    bool isPalindrome(ListNode* head)
    {
        if(head == NULL)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = NULL;
        ListNode* head1;
        if(head->next)
            fast = head->next->next;
        else
            return true;
        
        if(fast == NULL)
        {
            return (head->val == head->next->val);
        }
        if(fast->next == NULL)
        {
            return (head->val == fast->val);
        }
        
        while(fast)
        {
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            
            if(fast == NULL)
            {
                head1 = slow->next;
                slow->next = NULL;
                break;
            }
            if(fast->next == NULL)
            {
                head1 = slow->next->next;
                slow->next = NULL;
                break;
            }
        }
        
        head = reverse(head);
        return compare(head,head1);
    }
};
