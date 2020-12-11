//
//  reorder_list.cpp
//
//  Created by omlenka on 11/12/20.
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
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid = NULL;
        
        while(fast){
            if(fast->next == NULL || fast->next->next == NULL){
                mid = slow;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return mid;
    }
    int getLen(ListNode* head){
        int l = 0;
        while(head){
            l++;
            head = head->next;
        }
        return l;
    }
    void reorderUtil(ListNode* head, ListNode* &mid, ListNode* &prev, ListNode* &next, bool &evenLen){
        if(head == mid){
            prev = head;
            if(evenLen){
                next = head->next->next;
                head->next->next = NULL;
            }
            else{
                next = head->next;
                head->next = NULL;
            }
        }
        else{
            reorderUtil(head->next, mid, prev, next, evenLen);
            ListNode *tmp = next->next;
            head->next = next;
            head->next->next = prev;
            next = tmp;
            prev = head;
        }
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL){
            return;
        }
        ListNode *mid = getMiddle(head);
        ListNode *prev = NULL, *next = NULL;
        int len = getLen(head);
        bool evenLen = true;
        if(len & 1){
            evenLen = false;
        }
        reorderUtil(head, mid, prev, next, evenLen);
    }
};

int main(int argc, const char * argv[]) {
    Solution S;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    S.reorderList(head);
    return 0;
}
