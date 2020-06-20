//
//  climbing_stares.cpp
//
//  Created by omlenka on 20/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 1;
        if(n <= 2)
            return n;
        int n1 = 2;
        int n2 = 1;
        
        int i = 3;
        int res;
        while(i <= n)
        {
            res = n1+n2;
            n2 = n1;
            n1 = res;
            i++;
        }
        
        return res;
    }
};
