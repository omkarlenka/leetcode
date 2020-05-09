//
//  lru_cache.cpp
//
//  Created by omlenka on 09/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int key, val;
    Node* prev;
    Node* next;
    
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {
    int capacity;
    Node* head;
    Node* tail;
    unordered_multimap<int, Node*> M;
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key)
    {
        unordered_multimap<int, Node*>::iterator itr;
        itr = M.find(key);
        if(itr == M.end())
            return -1;
        Node* n = itr->second;
        int val = n->val;
        if(n == tail)
            return val;
        //move the element to last
        if(n->prev)
            n->prev->next = n->next;
        if(n->next)
            n->next->prev = n->prev;
        if(n == head)
        {
            if(head == tail)
                return val;
            head = head->next;
        }
        
        tail->next = n;
        n->next = NULL;
        n->prev = tail;
        tail = n;
        
        return val;
    }
    
    void put(int key, int val)
    {
        unordered_multimap<int, Node*>::iterator itr;
        itr = M.find(key);
        if(itr != M.end())
        {
            Node *n = itr->second;
            n->val = val;
            int x = get(key);
            return;
        }
        Node* n = new Node(key, val);
        
        
        if(M.empty())
        {
            head = n;
            tail = n;
        }
        else
        {
            if(M.size() >= capacity)
            {
                Node *tmp = head;
                if(head == tail)
                {
                    head = NULL;
                    tail = NULL;
                }
                else
                {
                    
                    head = head->next;
                    head->prev = NULL;
                }
                M.erase(tmp->key);
                delete tmp;
            }
            if(tail)
                tail->next = n;
            n->prev = tail;
            tail = n;
            if(!head)
                head = n;
        }
        M.insert(make_pair(key,n));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//["LRUCache","get","put","get","put","put","get","get"]
//[[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
int main()
{
    LRUCache* L = new LRUCache(2);
    L->put(2,1);
    L->put(2,2);
    cout << L->get(2);
    L->put(1,1);
    L->put(4,1);
    cout << L->get(2);
    return 0;
}
