//
//  insert_delete_getrandom_o1_lc380_OPTIMIZED.cpp
//
//  Created by omlenka on 17/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> M;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(M.find(val) != M.end()){
            return false;
        }
        v.push_back(val);
        M[val] = v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(M.find(val) == M.end()){
            return false;
        }
        int index = M[val];
        int last_element = v[v.size()-1];
        if(index != v.size()-1){
            swap(v[index], v[v.size()-1]);
            M[last_element] = index;
        }
        v.pop_back();
        M.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % v.size();
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
