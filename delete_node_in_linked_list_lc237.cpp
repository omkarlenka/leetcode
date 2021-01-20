//
//  delete_node_in_linked_list_lc237.cpp
//
//  Created by omlenka on 20/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

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
    void deleteNode(ListNode* node) {
        ListNode *tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        delete tmp;
    }
};
