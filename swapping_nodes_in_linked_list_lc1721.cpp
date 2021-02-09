//
//  swapping_nodes_in_linked_list_lc1721.cpp
//
//  Created by omlenka on 09/02/21.
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
    int getLength(ListNode* head){
        int l = 0;
        while(head){
            l++;
            head = head->next;
        }
        return l;
    }
    void swapNodes(ListNode* &head, ListNode* &l, ListNode* &r){
        //1->2->3->4
        //l : 1, r: 2
        ListNode* tmp1 = l->next;  //2
        ListNode* tmp2 = r->next;  //3
        
        tmp1->next = tmp2->next;
        l->next = tmp2;
        l->next->next = tmp1;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL)
            return head;
        int len = getLength(head);
        
        ListNode* left = head;
        ListNode* right = head;
        int i = k-1;
        while(i>1){
            left = left->next;
            i--;
        }
        i = len-k-1;
        while(i > 0){
            right = right->next;
            i--;
        }
        
        if(left == right){
            if(len == 2 && (k == 1 || k == 2)){
                ListNode* res = head->next;
                head->next->next = head;
                head->next = NULL;
                head = res;
            }
            return head;
        }
        
        if(k == 1){
            ListNode* left_next = left->next;
            ListNode* right_next = right->next;
            right->next = head;
            head->next = NULL;
            head = right_next;
            head->next = left_next;
        }
        else if(k == len){
            ListNode* left_next = left->next; //5
            ListNode* right_next = right->next; //2
            left->next = head;
            head->next = NULL;
            head = left_next;
            head->next = right_next;
        }
        else if(left->next == right || right->next == left){
            ListNode* l;
            ListNode* r;
            if(left->next == right){
                l = left;
                r = right;
            }
            else{
                l = right;
                r = left;
            }
            swapNodes(head,l,r);
        }
        else {
            ListNode* left_tmp = left->next->next; //3
            ListNode* right_tmp = right->next->next; //4
            
            ListNode* tmp = left->next;//2
            left->next = right->next;//1->3
            left->next->next = left_tmp; //1->5->3
            right->next = tmp;
            right->next->next = right_tmp;
        }
        return head;
    }
};
