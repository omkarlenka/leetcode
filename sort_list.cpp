//
//  sort_list.cpp
//
//  Created by omlenka on 27/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

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
    ListNode* getMiddle(ListNode* head)
    {
        if((head == NULL) || (head->next == NULL))
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* head = NULL;
        ListNode* cur = head;
        while(left && right)
        {
            ListNode* smaller;
            ListNode* greater;
            if(left->val < right->val)
            {
                smaller = left;
                greater = right;
            }
            else
            {
                smaller = right;
                greater = left;
            }
            if(head == NULL)
            {
                head = smaller;
                cur = head;
            }
            else
            {
                cur->next = smaller;
                cur = cur->next;
            }
            if(smaller == left)
                left = left->next;
            else
                right = right->next;
        }
        while(left)
        {
            cur->next = left;
            cur = cur->next;
            left = left->next;
        }
        while(right)
        {
            cur->next = right;
            cur = cur->next;
            right = right->next;
        }
        
        return head;
    }
    
public:
    ListNode* sortList(ListNode* head)
    {
        if((head == NULL) || (head->next == NULL))
            return head;
        ListNode* m = getMiddle(head);
        if(m)
        {
            ListNode* tmp = m->next;
            m->next = NULL;
            ListNode* left = sortList(head);
            ListNode* right = sortList(tmp);
            return merge(left,right);
        }
        
        return NULL;
    }
};


