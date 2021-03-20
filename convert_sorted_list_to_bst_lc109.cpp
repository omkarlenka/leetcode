//
//  convert_sorted_list_to_bst_lc109
//
//  Created by omlenka on 20/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void getMiddle(ListNode* head, ListNode* &prev, ListNode* &mid){
        ListNode* slow = head;
        prev = NULL;
        ListNode* fast = head->next;
        
        while(fast){
            prev = slow;
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                break;
        }
        mid = slow;
    }
    TreeNode* sortedListToBSTUtil(ListNode* head){
        if(head == NULL){
            return NULL;
        }
        
        ListNode *prev;
        ListNode *mid;
        getMiddle(head, prev, mid);
        TreeNode* root = NULL;
        
        if(mid){
            root = new TreeNode(mid->val);
        }
        else{
            return NULL;
        }
        
        if(prev){
            prev->next = NULL;
        }
        else{
            return root;
        }
        
        root->left = sortedListToBSTUtil(head);
        root->right = sortedListToBSTUtil(mid->next);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBSTUtil(head);
    }
};

int main() {
//    [-10,-3,0,5,9]
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    
    Solution S;
    TreeNode* root = S.sortedListToBST(head);
    return 0;
}
