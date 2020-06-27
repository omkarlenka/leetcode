//
//  linked_list_cycle.cpp
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if(head == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != slow)
        {
            if(fast == NULL || fast->next == NULL)
                return false;
            
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};


