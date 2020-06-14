//
//  reverse_nodes_in_k_group.cpp
//
//  Created by omlenka on 14/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

 class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    ListNode* reverseKGroupUtil(ListNode* head, int k, int len)
    {
        if(k > len)
            return head;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* tail = head;
        
        for(int j = 1;j<k;j++)
        {
            if(j == k-1)
            {
                head = curr;
            }
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        tail->next = reverseKGroupUtil(curr,k,len-k);
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int l = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            l++;
            curr = curr->next;
        }
        return reverseKGroupUtil(head,k,l);
    }
};



int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution S;
    ListNode* new_head = S.reverseKGroup(head, 2);
    return 0;
}
