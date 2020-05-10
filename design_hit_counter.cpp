//
//  design_hit_counter.cpp
//
//  Created by omlenka on 10/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;
class HitCounter
{
    map<int, int> M;
    int total;
public:
    /** Initialize your data structure here. */
    HitCounter()
    {
        total = 0;
    }
    
    /** Record a hit.
     @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp)
    {
        total++;
        M[timestamp] = total;
    }
    
    /** Return the number of hits in the past 5 minutes.
     @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp)
    {
        map<int, int>::iterator itr;
        itr = M.upper_bound(timestamp-300);
        int res;
        if(itr == M.begin())
        {
            res = total;
        }
        else
        {
            map<int, int>::iterator itr1  = prev(itr,1);
            res = total - itr1->second;
            M.erase(M.begin(), itr1);
        }
        if(M.empty())
            total = 0;
        return res;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
