//
//  middle_of_the_linked_list_lc876.cpp
//
//  Created by omlenka on 29/01/21.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        
        while(ptr2 && ptr2->next){
            ptr1 = ptr1->next;
            if(ptr2->next->next)
                ptr2 = ptr2->next->next;
            else{
                break;
            }
        }
        
        return ptr1;
    }
};
