//
//  reverse_integer.cpp
//
//  Created by omlenka on 15/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        if(x == 0)
            return 0;
        int res = 0;
        
        while(x != 0)
        {
            int n = x % 10;
            if(res > INT_MAX/10)
                return 0;
            else if(res == INT_MAX/10 && n > 7)
                return 0;
            else if(res < INT_MIN/10)
                return 0;
            else if(res == INT_MIN/10  & n < -8)
                return 0;
            res *= 10;
            res += n;
            x = x/10;
        }
        
        return res;
    }
};
