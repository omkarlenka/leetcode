//
//  snapshot_array.cpp
//
//  Created by omlenka on 24/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

class SnapshotArray {
    vector<map<int, int>> V;
    int snap_id;
public:
    SnapshotArray(int length)
    {
        V.resize(length,map<int,int>());
        snap_id = 0;
    }
    ~SnapshotArray()
    {
        V.clear();
    }
    
    void set(int index, int val)
    {
        auto itr = V[index].find(snap_id);
        if(itr == V[index].end())
            V[index][snap_id] = val;
        else
            itr->second = val;
    }
    
    int snap()
    {
        int tmp = snap_id++;
        return tmp;
    }
    
    int get(int index, int snap_id)
    {
        auto itr = V[index].lower_bound(snap_id);
        if(itr != V[index].end() && itr->first == snap_id)
        {
            return itr->second;
        }
        
        if(itr == V[index].begin())
            return 0;
        
        itr = prev(itr, 1);
        return itr->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
