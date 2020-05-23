//
//  mock_plus_one.cpp
//
//  Created by omlenka on 23/05/20.
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
        for(int i = digits.size()-1; i>=0; i--)
        {
            int val = digits[i] + carry;
            if(val >=10)
            {
                carry = val/10;
                val = val%10;
            }
            else
                carry = 0;
            
            res.push_back(val);
        }
        if(carry)
            res.push_back(carry);
        
        reverse(res.begin(),  res.end());
        return res;
    }
};
