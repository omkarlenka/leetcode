//
//  merge_in_between_linked_lists_lc1669.cpp
//
//  Created by omlenka on 05/02/21.
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2;
        int count = 0;
        while(ptr1){
            if(count == a-1){
                ptr2 = ptr1;
            }
            
            if(count == b){
                ptr1 = ptr1->next;
                break;
            }
            ptr1 = ptr1->next;
            count++;
        }
        
        ptr2->next = list2;
        
        ListNode* tail = list2;
        
        while(tail){
            if(tail->next == NULL)
                break;
            tail = tail->next;
        }
        
        tail->next = ptr1;
        
        return list1;
    }
};
