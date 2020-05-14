//
//  strobogrammatic-number.cpp
//
//  Created by omlenka on 15/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num)
    {
        int l = 0;
        int r = num.size()-1;
        while(l <= r)
        {
            if(l == r)
            {
                if(num[l] != '0' && num[l] !='1' && num[l] != '8')
                    return false;
            }
            if(num[l] == '0'|| num[l] =='1' || num[l] == '8')
            {
                if(num[r] != num[l])
                    return false;
            }
            else if(num[l] == '6')
            {
                if(num[r] != '9')
                    return false;
            }
            else if(num[l] == '9')
            {
                if(num[r] != '6')
                    return false;
            }
            else
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
