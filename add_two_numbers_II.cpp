//
//  main.cpp
//  add_two_numbers_II.cpp
//
//  Created by omlenka on 09/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    int getLength(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    void createNodeandUpdateRes(int val,int &carry, ListNode *&res){
        if(val >= 10){
            carry = 1;
            val = (val % 10);
        }
        else{
            carry = 0;
        }
        ListNode *node = new ListNode(val);
        node->next = res;
        res = node;
    }
    void addTwoNumbersUtil(ListNode* l1, ListNode* l2, ListNode *&res, int &diff, int &carry){
        if(diff > 0){
            addTwoNumbersUtil(l1->next, l2, res, --diff, carry);
            if(l1 == NULL)
                return;
            int val = carry + l1->val;
            createNodeandUpdateRes(val,carry, res);
        }
        else{
            if(l1 == NULL && l2 == NULL){
                return;
            }
            addTwoNumbersUtil(l1->next, l2->next, res, diff, carry);
            int val = carry + l1->val + l2->val;
            createNodeandUpdateRes(val,carry, res);
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode *res = NULL;
        int carry = 0;
        int len_l1 = getLength(l1);
        int len_l2 = getLength(l2);
        ListNode* larger = NULL;
        ListNode* smaller = NULL;
        int diff = 0;
        if(len_l1 > len_l2){
            diff = len_l1 - len_l2;
            larger = l1;
            smaller = l2;
        }
        else if(len_l2 > len_l1){
            diff = len_l2 - len_l1;
            larger = l2;
            smaller = l1;
        }
        else{
            larger = l1;
            smaller = l2;
        }
        
        addTwoNumbersUtil(larger, smaller, res, diff, carry);
        if(carry){
            int val = carry;
            int c = 0;
            createNodeandUpdateRes(val, c, res);
        }
        return res;
    }
};

int main() {
    Solution S;
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(1);
    
    ListNode* res = S.addTwoNumbers(l1, l2);
    
    return 0;
}
