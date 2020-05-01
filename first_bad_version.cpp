//
//  first_bad_version.cpp
//
//  Created by omlenka on 02/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        if(n == 1)
            return 1;
        int s = 1;
        int e = n;
        int firstBad = -1;
        while(firstBad == -1)
        {
            int m = e-(e-s)/2;
            if(isBadVersion(m))
            {
                if(m-1 >= 1)
                {
                    if(isBadVersion(m-1))
                    {
                        e = m-1;
                    }
                    else
                    {
                        firstBad = m;
                        break;
                    }
                }
                else
                {
                    firstBad = m;
                    break;
                }
                
            }
            else
                s = m+1;
        }
        return firstBad;
    }
};
