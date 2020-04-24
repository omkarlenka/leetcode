//
//  merge_k_sorted_lists.cpp
//
//  Created by omlenka on 24/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
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
class MinHeap
{
    ListNode ** heap;
    int heapsize;
public:
    MinHeap(vector<ListNode*> &v)
    {
        heapsize = v.size();
        heap = &v[0];
    }
    int left(int index)
    {
        int l = 2*index+1;
        if(l>=heapsize)
            return -1;
        return l;
    }
    int right(int index)
    {
        int r = 2*index+2;
        if(r>=heapsize)
            return -1;
        return r;
    }
    int parent(int index)
    {
        if(index >= 1)
        {
            return (index-1)/2;
        }
        return -1;
    }
    void replaceRoot(ListNode *n)
    {
        heap[0] = n;
        Heapify(0);
    }
    void deleteMin()
    {
        swap(heap[0],heap[heapsize-1]);
        heapsize--;
        Heapify(0);
        
    }
    void Heapify(int index)
    {
        if(index < 0 || heap[index] == NULL)
            return;
        int smaller = index;
        if(left(index) !=  -1 && heap[left(index)] && heap[left(index)]->val < heap[smaller]->val)
            smaller = left(index);
        if(right(index) != -1 && heap[right(index)] && heap[right(index)]->val < heap[smaller]->val)
            smaller = right(index);
        
        if(smaller != index)
        {
            swap(heap[index], heap[smaller]);
            Heapify(smaller);
        }
    }
    ListNode* getMin(){return heap[0];}
    bool isEmpty(){return (heapsize == 0);}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists_orig)
    {
        vector<ListNode *> lists;
        for(ListNode* l : lists_orig)
        {
            if(l)
                lists.push_back(l);
        }
        
        if(lists.size() == 0)
            return NULL;
        
        ListNode  * head = NULL;
        ListNode* res = NULL;
        MinHeap *H = new MinHeap(lists);
        int start;
        if(lists.size() > 1)
            start = H->parent(lists.size()-1);
        else
            start = 0;
        
        while(start >= 0)
        {
            H->Heapify(start--);
        }
        while(!H->isEmpty())
        {
            ListNode *n = H->getMin();
            ListNode *n1 = n->next;
            n->next = NULL;
            if(res == NULL)
            {
                head = n;
                res = head;
            }
            else
            {
                res->next = n;
                res = res->next;
            }
            
            if(n1)
            {
                H->replaceRoot(n1);
            }
            else
            {
                H->deleteMin();
            }
        }
        return head;
    }
};
