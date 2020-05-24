//
//  snapshot_array.cpp
//
//  Created by omlenka on 24/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
class SnapshotArray {
    unordered_map<int, unordered_map<int, int>> M;
    vector<int> v;
    set<int> modified;
    int snap_id;
public:
    SnapshotArray(int length)
    {
        v.resize(length, 0);
        snap_id = 0;
    }
    ~SnapshotArray()
    {
        v.clear();
        M.clear();
        modified.clear();
    }
    
    void set(int index, int val)
    {
        v[index] = val;
        modified.insert(index);
    }
    
    int snap()
    {
        unordered_map<int,int> inner_M;
        std::set<int>::iterator itr;
        for(itr = modified.begin(); itr != modified.end();itr++)
        {
            inner_M[*itr] = v[*itr];
            modified;
        }
        M[snap_id] = inner_M;
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id)
    {
        unordered_map<int, unordered_map<int, int>>::iterator itr = M.find(snap_id);
        
        if(itr != M.end())
        {
            unordered_map<int,int>::iterator inner_itr;
            inner_itr = itr->second.find(index);
            if(inner_itr == itr->second.end())
                return 0;
            else
            {
                return inner_itr->second;
            }
            
        }
        return -1;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
