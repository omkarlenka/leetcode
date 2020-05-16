//
//  insert_delete_getrandom_o1.cpp
//
//  Created by omlenka on 16/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class RandomizedSet {
    unordered_set<int> S;
    unordered_set<int>::iterator itr;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        itr = S.begin();
        // srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(S.find(val) == S.end())
        {
            S.insert(val);
            return  true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        itr = S.find(val);
        if(itr != S.end())
        {
            S.erase(itr);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        int i = rand() % S.size();
        itr = next(S.begin(), i);
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
