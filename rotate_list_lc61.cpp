//
//  rotate_list_lc61.cpp
//
//  Created by omlenka on 03/03/21.
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
    int getLengthAndTail(ListNode* head, ListNode* &tail){
        int n = 0;
        while(head){
            if(head->next == NULL)
                tail = head;
            head = head->next;
            n++;
        }
        return n;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode* tail = NULL;
        int n = getLengthAndTail(head, tail);
        
        if(k > n){
            k = k % n;
        }
        if(n == 1 || k == n){
            return head;
        }
        
        int count =  n-(k+1);
        ListNode* curr = head;
        while(count--){
            curr = curr->next;
        }
        tail->next = head;
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};
