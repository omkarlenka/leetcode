//
//  design_phone_directory.cpp
//
//  Created by omlenka on 21/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

class PhoneDirectory {
    set<int> S;  //set of available phone numbers
public:
    /** Initialize your data structure here
     @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers)
    {
        for(int i = 0;i<maxNumbers;i++)
            S.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
     @return - Return an available number. Return -1 if none is available. */
    int get()
    {
        if(!S.empty())
        {
            int n = *(--S.end());
            S.erase(--S.end());
            return n;
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number)
    {
        if(S.find(number) != S.end())
            return true;
        
        return false;
    }
    
    /** Recycle or release a number. */
    void release(int number)
    {
        S.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
