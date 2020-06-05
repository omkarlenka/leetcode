//
//  my_calendar_II.cpp
//
//  Created by omlenka on 05/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class MyCalendarTwo {
    map<int,int> M;
public:
    MyCalendarTwo()
    {
        
    }
    
    bool book(int start, int end)
    {
        M[start]++;
        M[end]--;
        map<int,int>::iterator itr;
        int overlap = 0;
        for(itr = M.begin();itr != M.end();itr++)
        {
            overlap += itr->second;
            if(overlap == 3)
            {
                M[start]--;
                M[end]++;
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
