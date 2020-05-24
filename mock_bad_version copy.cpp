//
//  mock_first_bad_version.cpp
//
//  Created by omlenka on 24/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    int _firstBadVersion(int s, int e)
    {
        if(s == e)
        {
            if(isBadVersion(s))
                return  s;
        }
        
        int m = s+(e-s)/2;
        
        if(isBadVersion(m))
        {
            if(m == 1 ||  isBadVersion(m-1) == false)
                return m;
            
            return _firstBadVersion(s, m-1);
        }
        else
            return _firstBadVersion(m+1, e);
        return -1;
    }
public:
    int firstBadVersion(int n)
    {
        return _firstBadVersion(1, n);
    }
};
