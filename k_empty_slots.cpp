//
//  k_empty_slots.cpp
//
//  Created by omlenka on 17/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K)
    {
        set<int> S;
        set<int>::iterator itr;
        set<int>::iterator pitr;
        set<int>::iterator nitr;
        
        for(int i = 0;i<bulbs.size();i++)
        {
            pair<set<int>::iterator, bool> p = S.insert(bulbs[i]);
            itr = p.first;
            if(itr != S.begin())
            {
                pitr = prev(itr,1);
                if(abs((*itr) - (*pitr)) == K+1)
                    return i+1;
            }
            
            nitr = next(itr,1);
            if(nitr !=  S.end()  && abs((*itr) - (*nitr)) == K+1)
                return i+1;
        }
        
        return -1;
    }
};
