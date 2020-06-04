//
//  product_of_array_except_self.cpp
//
//  Created by omlenka on 04/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> res(nums.size());
        int prod = 1;
        
        for(int i = 0;i<nums.size();i++)
        {
            prod *= nums[i];
            res[i] = prod;
        }
        prod = 1;
        for(int i = res.size()-1;i >=0;i--)
        {
            if(i-1 >= 0)
                res[i] = prod*res[i-1];
            else
                res[i] = prod;
            
            prod *= nums[i];
        }
        
        return res;
    }
};
