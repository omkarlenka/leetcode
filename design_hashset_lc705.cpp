//
//  design_hashset_lc705.cpp
//
//  Created by omlenka on 10/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MyHashSet{
    vector<bool> V;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        V.resize(1000001,false);
    }
    
    void add(int key) {
        V[key] = true;
    }
    
    void remove(int key) {
        V[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return V[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
