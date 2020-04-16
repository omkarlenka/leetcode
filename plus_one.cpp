//
//  plus_one.cpp
//
//  Created by omlenka on 16/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int carry = 1;
        vector<int> res;
        
        for(int i = digits.size()-1;i>=0;i--)
        {
            int n = digits[i]+carry;
            if(n>=10)
            {
                n = n%10;
                carry = 1;
            }
            else
                carry = 0;
            res.push_back(n);
        }
        if(carry)
            res.push_back(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};
