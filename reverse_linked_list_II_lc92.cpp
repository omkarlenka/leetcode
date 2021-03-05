//
//  reverse_linked_list_II_lc92.cpp
//
//  Created by omlenka on 05/03/21.
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
    ListNode* reverseBetween(ListNode* A, int m, int n) {
        if(A == NULL)
            return A;
        
        int count = 1;
        ListNode* prev_original = NULL;
        ListNode* prev = NULL;
        ListNode* curr = A;
        
        while(curr){
            if(count == m-1){
                prev_original= curr;
            }
            else if(count > m && count <= n){
                ListNode* tmp1 = curr->next;
                if(prev_original){
                    ListNode* tmp2 = prev_original->next;
                    prev_original->next = curr;
                    curr->next = tmp2;
                }
                else{
                    curr->next = A;
                    A = curr;
                }
                curr = tmp1;
                prev->next = curr;
                count++;
                continue;
            }
            if(count == n){
                break;
            }
            prev = curr;
            curr = curr->next;
            count++;
        }
        return A;
    }
};
