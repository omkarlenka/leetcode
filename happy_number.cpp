//
//  happy_number.cpp
//
//  Created by omlenka on 04/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int>  S;
        
        while(n != 1)
        {
            int n1 = 0;
            while(n != 0)
            {
                int d = n%10;
                n /= 10;
                n1 += d*d;
            }
            
            if(S.find(n1) != S.end())
                return false;
            n = n1;
            S.insert(n);
        }
        return true;
    }
};
